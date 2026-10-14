using BlobToDb.Models;
using Microsoft.Azure.Functions.Worker;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

string connectionString = "Server=WIN-M1S1T0RAR9G;Database=Blobs;Trusted_Connection=True;MultipleActiveResultSets=true;encrypt=false;";
var host = new HostBuilder()
    .ConfigureFunctionsWebApplication()
    .ConfigureServices(services =>
    {
        services.AddDbContext<AppDbContext>(options => {
            SqlServerDbContextOptionsExtensions.UseSqlServer(options, connectionString);
        });
        services.AddApplicationInsightsTelemetryWorkerService();
        services.ConfigureFunctionsApplicationInsights();
    })
    .Build();

host.Run();