using Azure.Storage;
using Azure.Storage.Blobs;
using Azure.Storage.Files.Shares;
using Azure.Storage.Files.Shares.Models;
using Azure.Storage.Sas;
using Microsoft.Extensions.Configuration;
using System.Threading.Tasks;

namespace FileShareDemo
{
    public class Program
    {
        static ShareClient shareClient;
        static string connectionString = "";
        static string accountKey = "";

        static async Task Main(string[] args)
        {
            var configuration = new ConfigurationBuilder().AddJsonFile("config.json").Build();
            var fileShare = configuration["FileShare"];
            connectionString = configuration["AzureConnString"];
            var blobContainer = configuration["BlobContainer"];
            accountKey = configuration["AccountKey"];

            shareClient = new ShareClient(connectionString, fileShare);
            await shareClient.CreateIfNotExistsAsync();

            string localDir = "./data/";
            if (!Directory.Exists(localDir))
            {
                Directory.CreateDirectory(localDir);
            }
            string localPath1 = Path.Combine(localDir, "sound.mp3");
            string localPath2 = Path.Combine(localDir, "dance.jfif");

            //await UploadToFileShare(localPath1, "music");
            //await UploadToFileShare(localPath2, "images");
            //await DownloadFromFileShare(Path.GetFileName(localPath1), "music");
            //await DownloadFromFileShare(Path.GetFileName(localPath2), "images");
            //await CopyFileShareToBlob(Path.GetFileName(localPath2), "images", blobContainer, "dance.jfif");
            //Uri uri = await GenerateSasForFileShare(Path.GetFileName(localPath2), "images");
            //Console.WriteLine(uri.ToString());

            await CopyFileInFileShare("sound.mp3", "music", "backup");

            await DisplayFileShare();
        }

        private static async Task CopyFileInFileShare(string fileName, string sourceDir, string targetDir)
        {
            try
            {
                ShareDirectoryClient sourceDirectory = shareClient.GetDirectoryClient(sourceDir);
                ShareDirectoryClient targetDirectory = shareClient.GetDirectoryClient(targetDir);

                if (!await sourceDirectory.ExistsAsync())
                {
                    Console.WriteLine($"Source directory '{sourceDir}' does not exist.");
                    return;
                }

                ShareFileClient sourceFile = sourceDirectory.GetFileClient(fileName);

                if (!await sourceFile.ExistsAsync())
                {
                    Console.WriteLine($"File '{fileName}' not found in '{sourceDir}'.");
                    return;
                }

                await targetDirectory.CreateIfNotExistsAsync();

                ShareFileClient targetFile = targetDirectory.GetFileClient(fileName);

                using (MemoryStream ms = new MemoryStream())
                {
                    ShareFileDownloadInfo download = await sourceFile.DownloadAsync();
                    await download.Content.CopyToAsync(ms);
                    ms.Position = 0;

                    await targetFile.CreateAsync(ms.Length);
                    await targetFile.UploadRangeAsync(new Azure.HttpRange(0, ms.Length), ms);
                }

                Console.WriteLine($"File '{fileName}' copied from '{sourceDir}' to '{targetDir}'");
            }
            catch (Exception ex)
            {
                Console.WriteLine("CopyFileInFileShare: " + ex.Message);
            }
        }

        private static async Task<Uri> GenerateSasForFileShare(string fileName, string dirName)
        {
            ShareSasBuilder sasBuilder = new ShareSasBuilder
            {
                ShareName = shareClient.Name,
                Resource = "f",
                FilePath = $"{dirName}/{fileName}",
                ExpiresOn = DateTimeOffset.UtcNow.AddHours(1)
            };
            sasBuilder.SetPermissions(ShareFileSasPermissions.Read | ShareFileSasPermissions.Write);
            StorageSharedKeyCredential credential = new StorageSharedKeyCredential(shareClient.AccountName, accountKey);
            UriBuilder builder = new UriBuilder(
                $"https://{shareClient.AccountName}.file.core.windows.net/{sasBuilder.ShareName}/{sasBuilder.FilePath}"
            );
            builder.Query = sasBuilder.ToSasQueryParameters(credential).ToString();
            return builder.Uri;
        }

        private static async Task CopyFileShareToBlob(string fileName, string dirName, string blobContainer, string blobName)
        {
            try
            {
                ShareDirectoryClient directoryClient = shareClient.GetDirectoryClient(dirName);
                if (await directoryClient.ExistsAsync())
                {
                    ShareFileClient fileClient = directoryClient.GetFileClient(fileName);
                    if (await fileClient.ExistsAsync())
                    {
                        BlobContainerClient blobContainerClient = new BlobContainerClient(connectionString, blobContainer);
                        await blobContainerClient.CreateIfNotExistsAsync();
                        BlobClient blobClient = blobContainerClient.GetBlobClient(blobName);
                        await blobClient.UploadAsync(fileClient.OpenRead(), true);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("CopyFileShareToBlob: " + ex.Message);
            }
        }

        private static async Task DownloadFromFileShare(string fileName, string dirName = "dir1")
        {
            try
            {
                ShareDirectoryClient directoryClient = shareClient.GetDirectoryClient(dirName);
                if (await directoryClient.ExistsAsync())
                {
                    ShareFileClient fileClient = directoryClient.GetFileClient(fileName);
                    string localDir = "./download/";
                    if (!Directory.Exists(localDir))
                    {
                        Directory.CreateDirectory(localDir);
                    }
                    using (FileStream fs = File.OpenWrite(Path.Combine(localDir, fileName)))
                    {
                        ShareFileDownloadInfo info = await fileClient.DownloadAsync();
                        await info.Content.CopyToAsync(fs);
                        Console.WriteLine($"Downloaded {fileName} to {localDir}");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("DownloadFromFileShare: " + ex.Message);
            }
        }

        private static async Task DisplayFileShare()
        {
            try
            {
                ShareDirectoryClient rootDirectory = shareClient.GetRootDirectoryClient();
                await DisplayDirectory(rootDirectory);
            }
            catch (Exception ex)
            {
                Console.WriteLine("DisplayFileShare: " + ex.Message);
            }
        }

        private static async Task DisplayDirectory(ShareDirectoryClient directory)
        {
            await foreach (ShareFileItem item in directory.GetFilesAndDirectoriesAsync())
            {
                if (item.IsDirectory)
                {
                    Console.WriteLine("Directory " + item.Name + ":");
                    Console.WriteLine("---------------------------------------------------------------");
                    ShareDirectoryClient dc = directory.GetSubdirectoryClient(item.Name);
                    await DisplayDirectory(dc);
                    Console.WriteLine("---------------------------------------------------------------");
                }
                else
                {
                    Console.WriteLine("\t\t" + item.Name + " - " + item.FileSize);
                }
            }
        }

        private static async Task UploadToFileShare(string localPath, string dir = "dir1")
        {
            try
            {
                ShareDirectoryClient directoryClient = shareClient.GetDirectoryClient(dir);
                await directoryClient.CreateIfNotExistsAsync();
                ShareFileClient fileClient = directoryClient.GetFileClient(Path.GetFileName(localPath));

                using (FileStream stream = File.OpenRead(localPath))
                {
                    await fileClient.CreateAsync(stream.Length);
                    await fileClient.UploadRangeAsync(new Azure.HttpRange(0, stream.Length), stream);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("UploadToFileShare: " + ex.Message);
            }
        }
    }
}