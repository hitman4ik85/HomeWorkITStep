using AuctionMvc.Models;
using Azure.Data.Tables;
using Azure.Storage.Blobs;
using Microsoft.AspNetCore.Mvc;
using System.Runtime.InteropServices.ObjectiveC;

namespace AuctionMvc.Controllers
{
    public class AuthController : Controller
    {
        private readonly BlobContainerClient blobContainer;
        private readonly TableClient tableClient;

        public AuthController(BlobContainerClient blobContainer, TableClient tableClient)
        {
            this.blobContainer = blobContainer;
            this.tableClient = tableClient;
        }

        public IActionResult Index()
        {
            string? loggedId = HttpContext.Session.GetString("LoggedId");
            if (string.IsNullOrEmpty(loggedId))
            {
                return RedirectToAction("Login");
            }

            User fromTable = tableClient
                .Query<User>(u => u.RowKey == loggedId)
                .FirstOrDefault();

            return View(fromTable);
        }

        [HttpGet]
        public IActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Register(User user, IFormFile AvatarUrl)
        {
            //Check email uniqueness
            //add user to table storage
            //add avatar to blob storage
            User fromTable = tableClient.Query<User>(u => u.Email == user.Email).FirstOrDefault();
            if (fromTable != null)
            {
                ViewBag.ErrorMessage = "This Email is already registered!";
                return View();
            }
            if (AvatarUrl == null)
            {
                ViewBag.ErrorMessage = "You must select Avatar image!";
                return View();
            }
            
            BlobClient blobClient = blobContainer.GetBlobClient(user.RowKey + ".jpg");
            await blobClient.UploadAsync(AvatarUrl.OpenReadStream());

            user.AvatarUrl = blobClient.Uri.ToString();
            await tableClient.AddEntityAsync<User>(user);

            return RedirectToAction("Login");
        }
        [HttpGet]
        public IActionResult Login()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Login(User user)
        {
            User fromTable = tableClient.
                Query<User>(u => u.Email == user.Email && u.Password == user.Password).
                FirstOrDefault();
            if (fromTable != null)
            {
                HttpContext.Session.SetString("LoggedId", fromTable.RowKey);
                HttpContext.Session.SetString("LoggedEmail", fromTable.Email);
                return RedirectToAction("Index");
            }
            return View();
        }
        [HttpPost]
        public IActionResult AddFunds([FromBody] float funds)
        {
            string? userId = HttpContext.Session.GetString("LoggedId");
            if (string.IsNullOrEmpty(userId))
            {
                return Json(new { success = false, message = "User not logged in" });
            }

            var user = tableClient.Query<User>(u => u.RowKey == userId).FirstOrDefault();
            if (user == null)
            {
                return Json(new { success = false, message = "User not found" });
            }

            user.Balance += (int)funds;
            tableClient.UpdateEntity(user, user.ETag, Azure.Data.Tables.TableUpdateMode.Replace);
            return Json(new { success = true });
        }

    }
}
