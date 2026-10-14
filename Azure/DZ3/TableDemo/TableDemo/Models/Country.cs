using Azure;
using Azure.Data.Tables;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TableDemo.Models
{
    public class Country : ITableEntity
    {
        public string CountryName { get; set; }
        public string Capital { get; set; }
        public int Population { get; set; }
        public DateTime CreatedAt { get; set; }


        public string PartitionKey { get; set; }
        public string RowKey { get; set; }
        public DateTimeOffset? Timestamp { get; set; }
        public ETag ETag { get; set; }

        public Country(string countryName, string capital, int population)
        {
            CountryName = countryName;
            Capital = capital;
            Population = population;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Countries";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTimeOffset.UtcNow;
            ETag = new ETag();
        }

        public Country()
        {
            CountryName = "";
            Capital = "";
            Population = 0;
            CreatedAt = DateTime.UtcNow;

            PartitionKey = "Countries";
            RowKey = Guid.NewGuid().ToString();
            Timestamp = DateTimeOffset.UtcNow;
            ETag = new ETag();
        }
    }
}
