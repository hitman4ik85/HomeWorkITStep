using Azure;
using Azure.Data.Tables;
using System;

namespace AuctionMvc.Models
{
    public class Lot : ITableEntity
    {
        public string UserRowKey { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public int Price { get; set; }
        public string PictureUrl { get; set; }
        public int LotStatus { get; set; }

        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public Lot(string userRowKey, string name, string description, int price, string pictureUrl)
        {
            UserRowKey = userRowKey;
            Name = name;
            Description = description;
            Price = price;
            PictureUrl = pictureUrl;
            LotStatus = 0;

            PartitionKey = "Lot";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();
        }

        public Lot()
        {
            UserRowKey = "";
            Name = "";
            Description = "";
            Price = 0;
            PictureUrl = "";
            LotStatus = 0;

            PartitionKey = "Lot";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();
        }
    }
}
