using Azure;
using Azure.Data.Tables;
using Microsoft.Extensions.Configuration;
using System.Dynamic;
using TableDemo.Models;

namespace TableDemo
{
    public class Program
    {
        static string tableName;
        static TableServiceClient serviceClient;
        static async Task Main(string[] args)
        {
            var configuration = new ConfigurationBuilder()
                .AddJsonFile("config.json")
                .Build();

            var connectionString = configuration["AzureConnString"];
            tableName = configuration["Table"];

            serviceClient = new TableServiceClient(connectionString);
            serviceClient.CreateTableIfNotExists(tableName);

            Country c1 = new Country("USA", "Washington, D.C.", 331002651);
            Country c2 = new Country("Canada", "Ottawa", 37742154);
            Country c3 = new Country("Ukraine", "Kyiv", 38932753);

            Country c4 = new Country("Germany", "Berlin", 83783942);
            Country c5 = new Country("France", "Paris", 65273511);
            Country c6 = new Country("Italy", "Rome", 60244639);

            List<Country> countries = new List<Country> { c1, c4, c5, c6 };

            City city1 = new City("New York", 8419600, false);
            City city2 = new City("Kyiv", 2967360, true);
            City city3 = new City("Toronto", 2731571, true);

            List<City> cities = new List<City> { city1, city2, city3 };

            //await UpsertObjectIntoTable<Country>(c3);
            //await UpsertObjectIntoTable<City>(city2);

            //Country c4 = await GetEntityById<Country>("Countries", "rowkey_here");
            //City city = await GetEntityById<City>("Cities", "rowkey_here");

            //await DeleteEntity<Country>("Countries", "rowkey_here");
            //await DeleteEntity<City>("Cities", "rowkey_here");

            //await SimpleBatch<Country>(countries);
            //await SimpleBatch<City>(cities);

            //await MixedBatch<Country>();
            //await MixedBatch<City>();

            await DisplayTableContent<Country>();
            await DisplayTableContent<City>();
        }

        private static async Task MixedBatch<T>() where T : class, ITableEntity
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                T entity = await GetEntityById<T>("Countries", "6bb99fe9-87ce-4c6c-8f72-53f7f8836c06");
                entity.PartitionKey = "Asia Country";
                TableEntity entity1 = new TableEntity("Asia Country", Guid.NewGuid().ToString())
                {
                    { "Title", "Goblin Reservation" },
                    { "Author", "Clifford Simak" },
                    { "Price", 240 },
                    { "Created", DateTime.UtcNow },
                };
                TableTransactionAction update = new TableTransactionAction(TableTransactionActionType.UpdateMerge, entity);
                TableTransactionAction add = new TableTransactionAction(TableTransactionActionType.UpdateReplace, entity1);
                List<TableTransactionAction> actions = new List<TableTransactionAction> { update, add };
                await tableClient.SubmitTransactionAsync(actions);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        private static async Task SimpleBatch<T>(List<T> list) where T : ITableEntity
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                List<TableTransactionAction> actions = new List<TableTransactionAction>();
                foreach (var item in list)
                {
                    actions.Add(new TableTransactionAction(TableTransactionActionType.Add, item));
                }
                await tableClient.SubmitTransactionAsync(actions);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        private static async Task DeleteEntity<T>(string pk, string rk)
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                await tableClient.DeleteEntityAsync(pk, rk);
                Console.WriteLine("Entity deleted!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        private async static Task<T> GetEntityById<T>(string pk, string rk) where T : class, ITableEntity
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                Response<T> response = tableClient.GetEntity<T>(pk, rk);
                Console.WriteLine("Entity received!:");
                return response.Value;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
                return null;
            }
        }

        private static async Task UpsertObjectIntoTable<T>(T c3) where T : ITableEntity
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                await tableClient.UpsertEntityAsync(c3, TableUpdateMode.Replace);
                Console.WriteLine("New oblect upserted!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        private static async Task DisplayTableContent<T>() where T : class, ITableEntity
        {
            try
            {
                TableClient tableClient = serviceClient.GetTableClient(tableName);
                Pageable<T> list = tableClient.Query<T>();

                Console.WriteLine("Table content:");
                foreach (var item in list)
                {
                    if (item.PartitionKey == "Countries")
                    {
                        Console.WriteLine((item as Country).CountryName + " : " + (item as Country).Capital + " : " + (item as Country).Population);
                    }
                    else if (item.PartitionKey == "Cities")
                    {
                        Console.WriteLine((item as City).Name + " : " + (item as City).Population + " : " + ((item as City).IsCapital ? "Capital" : "City"));
                    }
                    else
                    {
                        Console.WriteLine(item.PartitionKey + " : " + item.RowKey);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
    }
}
// Update, Insrt => Upsert
