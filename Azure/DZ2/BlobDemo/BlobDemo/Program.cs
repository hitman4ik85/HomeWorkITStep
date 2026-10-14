using Azure.Storage.Blobs;
using Azure.Storage.Blobs.Models;
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

            // === Домашнє 1: Студент ===
            Student st = new Student() { Name = "Andriy", Age = 40, Group = "PV311" };
            await UploadStudent(connectionString, container, st, "student.json");

            Student downloaded = await DownloadStudent(connectionString, container, "student.json");
            Console.WriteLine($"Student: {downloaded.Name}, Age: {downloaded.Age}, Group: {downloaded.Group}");

            // === Домашнє 2: Будь-який клас ===
            Book book = new Book() { Title = "Azure for Beginners", Author = "Anonim", Year = 2025 };
            await UploadAnyObject(connectionString, container, book, "book.json");

            await DisplayContainer(connectionString, container);
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

        private static async Task UploadAnyObject<T>(string connectionString, string container, T obj, string fileName)
        {
            BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
            BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(container);

            BlobClient blobClient = containerClient.GetBlobClient(fileName);

            string json = JsonSerializer.Serialize(obj);
            using var ms = new MemoryStream(Encoding.UTF8.GetBytes(json));
            await blobClient.UploadAsync(ms, true);

            Console.WriteLine($"*** Object of type '{typeof(T).Name}' uploaded to Blob as '{fileName}'!");
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
    }
}
