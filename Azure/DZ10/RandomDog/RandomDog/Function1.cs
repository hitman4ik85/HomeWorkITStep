using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;
using Microsoft.Azure.WebJobs.Extensions.Http;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Logging;
using RandomDog.Models;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Net.Http;

namespace RandomDog
{
    public static class Function1
    {
        [FunctionName("Function1")]
        public static async Task<IActionResult> Run(
            [HttpTrigger(AuthorizationLevel.Anonymous, "get", "post", Route = null)] HttpRequest req,
            ILogger log)
        {
            string url = "https://random.dog/woof.json";

            Dog dog = null;

            JsonSerializerOptions options = new JsonSerializerOptions
            {
                PropertyNameCaseInsensitive = true
            };
            options.Converters.Add(new JsonStringEnumConverter());

            using (HttpClient client = new HttpClient())
            {
                var response = await client.GetAsync(url);

                if (response.IsSuccessStatusCode)
                {
                    string json = await response.Content.ReadAsStringAsync();
                    dog = System.Text.Json.JsonSerializer.Deserialize<Dog>(json, options);

                    return new OkObjectResult(dog);
                }
                else
                {
                    return new BadRequestObjectResult("Failed to fetch dog info.");
                }
            }
        }
    }
}
