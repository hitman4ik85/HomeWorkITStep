using System.IO;
using System.Threading.Tasks;
using BlobToDb.Models;
using Microsoft.Azure.Functions.Worker;
using Microsoft.Extensions.Logging;

namespace BlobToDb
{
    public class Function1
    {
        private readonly AppDbContext context;

        public Function1(AppDbContext context)
        {
            this.context = context;
        }

        [Function(nameof(Function1))]
        public async Task Run(
            [BlobTrigger("c311/{name}", Connection = "ConnString")] Stream blobIn, string name)
        {
            int size = 0;
            string b64 = string.Empty;

            using (MemoryStream ms = new MemoryStream())
            {
                blobIn.CopyTo(ms);
                byte[] data = ms.ToArray();
                b64 = Convert.ToBase64String(data);
                size = data.Length;
            }

            BlobItem blob = new BlobItem() {
                Size = size,
                PictureUrl = b64
            };
            context.BlobItem.Add(blob);
            context.SaveChanges();
        }
    }
}
