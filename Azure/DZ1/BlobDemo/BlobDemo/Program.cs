using Azure.Storage.Blobs;
using Azure.Storage.Blobs.Models;
using Azure.Storage.Blobs.Specialized;
using Azure.Storage.Sas;
using Microsoft.Extensions.Configuration;
using System.Text;
using System.Text.Json;

namespace BlobDemo
{
    public class Program
    {
        static async Task Main(string[] args)
        {
            string localPath = "./data";
            if (!Directory.Exists(localPath))
            {
                Directory.CreateDirectory(localPath);
            }

            var configuration = new ConfigurationBuilder().AddJsonFile("config.json").Build();
            string connectionString = configuration["AzureConnString"];
            string container = configuration["BlobContainer"];

            // === Blob частина уроку
            //await CreateContainer(connectionString, container);
            //await UploadBlob(connectionString, container, "./data/small.jpg");
            //await DeleteBlob(connectionString, container, "small.jpg");
            //await DownloadBlob(connectionString, container, "big.jpg");
            //Uri uri = await CreateSasForBlob(connectionString, container, "big.jpg");

            // === Студент ===
            Student st = new Student() { Name = "Andriy", Age = 40, Group = "PV311" };
            await UploadStudent(connectionString, container, st, "student.json");

            Student downloaded = await DownloadStudent(connectionString, container, "student.json");
            Console.WriteLine($"Student: {downloaded.Name}, Age: {downloaded.Age}, Group: {downloaded.Group}");

            await DisplayContainer(connectionString, container);
        }

        private static async Task<Uri> CreateSasForBlob(string? connectionString, string? container, string blobName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(blobName);

            if (blobClient.CanGenerateSasUri)
            {
                BlobSasBuilder sasBuilder = new BlobSasBuilder()
                {
                    BlobContainerName = blobClient.GetParentBlobContainerClient().Name,
                    BlobName = blobClient.Name,
                    Resource = "b",
                    ExpiresOn = DateTimeOffset.UtcNow.AddMinutes(30)
                };
                sasBuilder.SetPermissions(BlobAccountSasPermissions.Read);
                Uri uri = blobClient.GenerateSasUri(sasBuilder);
                Console.WriteLine(uri.ToString());
                return uri;
            }
            return null;
        }

        private static async Task DownloadBlob(string? connectionString, string? container, string blobName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(blobName);
            string localDir = "./data";
            string localPath = Path.Combine(localDir, blobName);

            string ext = Path.GetExtension(localPath);
            localPath = localPath.Replace(ext, "_blob" + ext);
            await blobClient.DownloadToAsync(localPath);
            Console.WriteLine("*** Blob " + blobName + " was downloaded!");
        }

        private static async Task DeleteBlob(string? connectionString, string? container, string blobName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(blobName);
            await blobClient.DeleteIfExistsAsync(DeleteSnapshotsOption.IncludeSnapshots);
            Console.WriteLine("*** Blob " + blobName + " was deleted!");
        }

        private static async Task DisplayContainer(string? connectionString, string? container)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);
            Console.WriteLine("*** Content of " + container + ":");
            await foreach (BlobItem item in containerClient.GetBlobsAsync())
            {
                Console.Write("\t" + item.Name);
                Console.Write("\t\tSize:\t" + item.Properties.ContentLength);
                Console.Write("\t\tExpire date:\t" + item.Properties.ExpiresOn.ToString());
                Console.WriteLine("\r\n---------------------------------------------------------------------------------");
            }
        }

        private static async Task UploadBlob(string? connectionString, string? container, string path)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            string blobName = Path.GetFileName(path);
            BlobClient blobClient = containerClient.GetBlobClient(blobName);
            await blobClient.UploadAsync(path);

            Console.WriteLine("*** Blob " + blobName + " was created!");
        }

        private static async Task CreateContainer(string? connectionString, string? container)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = await serviceClient.CreateBlobContainerAsync(container);
            Console.WriteLine("*** Container " + container + " was created!");
        }

        private static async Task UploadStudent(string connectionString, string container, Student student, string fileName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(fileName);

            string json = JsonSerializer.Serialize(student);
            using var ms = new MemoryStream(Encoding.UTF8.GetBytes(json));
            await blobClient.UploadAsync(ms, true);

            Console.WriteLine($"*** Student object '{fileName}' uploaded to Blob!");
        }

        private static async Task<Student> DownloadStudent(string connectionString, string container, string fileName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(fileName);
            var download = await blobClient.DownloadAsync();

            using var reader = new StreamReader(download.Value.Content);
            string json = await reader.ReadToEndAsync();
            Student student = JsonSerializer.Deserialize<Student>(json);

            Console.WriteLine($"*** Student object '{fileName}' downloaded from Blob!");
            return student;
        }
    }
}
