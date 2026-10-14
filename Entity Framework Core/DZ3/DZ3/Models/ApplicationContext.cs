using Microsoft.EntityFrameworkCore;

namespace DZ3.Models
{
    public class ApplicationContext : DbContext
    {
        public DbSet<Product> Products { get; set; } = null!;
        public DbSet<Customer> Customers { get; set; } = null!;
        public DbSet<Order> Orders { get; set; } = null!;

        public ApplicationContext()
        {
            Database.EnsureDeleted();
            Database.EnsureCreated();
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlite("Data Source=store.db");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Product>().HasData(
                new Product { Id = 1, ProductName = "Iphone 12", Manufacturer = "Apple", ProductCount = 15, Price = 20000 },
                new Product { Id = 2, ProductName = "Pixel 6A", Manufacturer = "Google", ProductCount = 12, Price = 10000 },
                new Product { Id = 3, ProductName = "Iphone 13", Manufacturer = "Apple", ProductCount = 12, Price = 25000 },
                new Product { Id = 4, ProductName = "Galaxy S22", Manufacturer = "Samsung", ProductCount = 14, Price = 19000 },
                new Product { Id = 5, ProductName = "Galaxy S24", Manufacturer = "Samsung", ProductCount = 12, Price = 64000 },
                new Product { Id = 6, ProductName = "13 Pro 5G", Manufacturer = "Xiaomi", ProductCount = 16, Price = 40000 },
                new Product { Id = 7, ProductName = "Pixel 8 Pro", Manufacturer = "Google", ProductCount = 12, Price = 50000 }
            );

            modelBuilder.Entity<Customer>().HasData(
                new Customer { Id = 1, FirstName = "Tom" },
                new Customer { Id = 2, FirstName = "Bob" },
                new Customer { Id = 3, FirstName = "Sam" }
            );

            modelBuilder.Entity<Order>().HasData(
                new Order { Id = 1, ProductId = 1, CustomerId = 1, CreatedAt = new DateTime(2024, 9, 20), ProductCount = 2, Price = 20000 },
                new Order { Id = 2, ProductId = 4, CustomerId = 1, CreatedAt = new DateTime(2024, 9, 20), ProductCount = 1, Price = 19000 },
                new Order { Id = 3, ProductId = 7, CustomerId = 2, CreatedAt = new DateTime(2024, 8, 20), ProductCount = 1, Price = 50000 },
                new Order { Id = 4, ProductId = 7, CustomerId = 2, CreatedAt = new DateTime(2024, 8, 24), ProductCount = 1, Price = 50000 }
            );
        }
    }
}
