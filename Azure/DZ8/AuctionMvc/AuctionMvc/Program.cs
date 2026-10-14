using AuctionMvc.WsHub;
using Azure.Data.Tables;
using Azure.Storage.Blobs;
using Azure.Storage.Queues;

namespace AuctionMvc
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var configuration = new ConfigurationBuilder().AddJsonFile("appsettings.json").Build();
            string connectionString = configuration.GetConnectionString("AzureConnection");
            string blobContainer = configuration["BlobContainer"];
            string tableName = configuration["TableName"];
            string queueName = configuration["QueueName"];

            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddControllersWithViews();

            // Add SignalR services
            builder.Services.AddSignalR();

            //connect to Blob Storage
            builder.Services.AddSingleton(options => {
                BlobServiceClient serviceClient = new BlobServiceClient(connectionString);
                BlobContainerClient containerClient = serviceClient.GetBlobContainerClient(blobContainer);
                containerClient.CreateIfNotExists();
                return containerClient;
            });

            //connect to Table Storage
            builder.Services.AddSingleton(options => {
                TableServiceClient serviceClient = new TableServiceClient(connectionString);
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                tableClient.CreateIfNotExists();
                return tableClient;
            });

            //connect to Queue Storage
            builder.Services.AddSingleton(options => {
                QueueClient queueClient = new QueueClient(connectionString, queueName);
                queueClient.CreateIfNotExists();
                return queueClient;
            });

            // Sessin to use only in code
            builder.Services.AddSession(options => {
                options.IdleTimeout = TimeSpan.FromMinutes(20);
                options.Cookie.HttpOnly = true;
                options.Cookie.IsEssential = true;
            });

            // Sessin to use only on wiews
            builder.Services.AddHttpContextAccessor();

            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (!app.Environment.IsDevelopment())
            {
                app.UseExceptionHandler("/Home/Error");
            }
            app.UseStaticFiles();

            app.UseRouting();

            app.UseSession();

            app.UseAuthorization();

            app.MapControllerRoute(
                name: "default",
                pattern: "{controller=Auth}/{action=Login}/{id?}");

            app.MapHub<AuctionHub>("/bid");

            app.Run();
        }
    }
}
