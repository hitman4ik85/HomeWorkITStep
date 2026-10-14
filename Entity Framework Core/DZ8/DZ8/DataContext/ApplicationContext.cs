using DZ8.Models;
using Microsoft.EntityFrameworkCore;

namespace DZ8.DataContext;

public class ApplicationContext : DbContext
{
    public DbSet<Product> Products { get; set; } = null!;
    public DbSet<Order> Orders { get; set; } = null!;
    public DbSet<Customer> Customers { get; set; } = null!;

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlite("Data Source=PhoneStore.db");
    }
}
