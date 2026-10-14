using Azure;
using Azure.Data.Tables;
using System;

namespace TableDemo.Models
{
    public class City : ITableEntity
    {
        public string Name { get; set; }
        public int Population { get; set; }
        public bool IsCapital { get; set; }
        public DateTime CreatedAt { get; set; }

        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public City(string name, int population, bool isCapital)
        {
            Name = name;
            Population = population;
            IsCapital = isCapital;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Cities";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTimeOffset.UtcNow;
            ETag = new ETag();
        }

        public City()
        {
            Name = "";
            Population = 0;
            IsCapital = false;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Cities";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTimeOffset.UtcNow;
            ETag = new ETag();
        }
    }
}
