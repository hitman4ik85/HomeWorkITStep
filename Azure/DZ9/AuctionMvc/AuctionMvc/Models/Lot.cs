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
        public int MaxPrice { get; set; }
        public string PictureUrl { get; set; }
        public int LotStatus { get; set; }

        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public Lot()
        {
            PartitionKey = "Lot";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();
        }
    }
}
