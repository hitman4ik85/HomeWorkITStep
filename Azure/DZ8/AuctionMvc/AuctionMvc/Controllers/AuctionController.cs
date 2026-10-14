using AuctionMvc.Models;
using Azure.Data.Tables;
using Azure.Storage.Blobs;
using Azure.Storage.Queues;
using Microsoft.AspNetCore.Mvc;

namespace AuctionMvc.Controllers
{
    public class AuctionController : Controller
    {
        private readonly BlobContainerClient blobContainer;
        private readonly TableClient tableClient;
        private readonly QueueClient queueClient;

        public AuctionController(BlobContainerClient blobContainer, TableClient tableClient, QueueClient queueClient)
        {
            this.blobContainer = blobContainer;
            this.tableClient = tableClient;
            this.queueClient = queueClient;
        }

        public IActionResult Index()
        {
            string? userKey = HttpContext.Session.GetString("LoggedId");
            if (string.IsNullOrEmpty(userKey))
            {
                return RedirectToAction("Login", "Auth");
            }
            var list = tableClient.Query<Lot>(l => l.PartitionKey == "Lot").ToList();
            return View(list);
        }

        [HttpPost]
        public async Task<IActionResult> AddLot(Lot lot, IFormFile PictureUrl)
        {
            string? userKey = HttpContext.Session.GetString("LoggedId");
            if (string.IsNullOrEmpty(userKey))
            {
                return RedirectToAction("Login", "Auth");
            }

            if (PictureUrl == null)
            {
                ViewBag.ErrorMessage = "You must select a picture for the lot!";
                return RedirectToAction("Index", "Auth");
            }

            BlobClient blobClient = blobContainer.GetBlobClient(lot.RowKey + ".jpg");
            await blobClient.UploadAsync(PictureUrl.OpenReadStream());

            lot.UserRowKey = userKey;
            lot.PictureUrl = blobClient.Uri.ToString();
            lot.MaxPrice = lot.Price * 3;
            await tableClient.AddEntityAsync<Lot>(lot);

            ViewBag.SuccessMessage = "Lot successfully added!";
            return RedirectToAction("Index");
        }
    }
}
