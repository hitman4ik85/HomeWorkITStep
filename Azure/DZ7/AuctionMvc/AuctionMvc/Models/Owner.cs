using Azure;
using Azure.Data.Tables;
using System;

namespace AuctionMvc.Models
{
    public class Owner : ITableEntity
    {
        public string LotRowKey { get; set; }
        public int Balance { get; set; }
        public DateTime CreatedAt { get; set; }

        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public Owner(string lotRowKey, int balance)
        {
            LotRowKey = lotRowKey;
            Balance = balance;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Owner";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();
        }

        public Owner()
        {
            LotRowKey = "";
            Balance = 0;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Owner";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTime.UtcNow;
            ETag = new ETag();
        }
    }
}
