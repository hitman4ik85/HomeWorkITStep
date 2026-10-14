using DZ8.DataContext;
using DZ8.Models;
using Microsoft.EntityFrameworkCore;

using (ApplicationContext db = new ApplicationContext())
{
    db.Database.EnsureDeleted();
    db.Database.EnsureCreated();

    Customer customer1 = new Customer { Name = "John Doe", Email = "john@gmail.com" };
    Customer customer2 = new Customer { Name = "Jane Smith", Email = "jane@gmail.com" };
    Customer customer3 = new Customer { Name = "Alex Johnson", Email = "alex@gmail.com" };
    db.Customers.AddRange(customer1, customer2, customer3);

    Product product1 = new Product { Name = "iPhone 14", Price = 999.99 };
    Product product2 = new Product { Name = "Samsung Galaxy S23", Price = 899.99 };
    Product product3 = new Product { Name = "Google Pixel 7", Price = 799.99 };
    Product product4 = new Product { Name = "OnePlus 11", Price = 729.99 };
    Product product5 = new Product { Name = "Sony Xperia 5", Price = 849.99 };
    Product product6 = new Product { Name = "Xiaomi Mi 13", Price = 699.99 };
    Product product7 = new Product { Name = "Huawei P60", Price = 749.99 };
    Product product8 = new Product { Name = "Motorola Edge 40", Price = 649.99 };
    Product product9 = new Product { Name = "Oppo Find X5", Price = 799.99 };
    Product product10 = new Product { Name = "Asus ROG Phone 6", Price = 1199.99 };
    db.Products.AddRange(product1, product2, product3, product4, product5, product6, product7, product8, product9, product10);

    Order order1 = new Order
    {
        Customer = customer1,
        Products = new List<Product> { product1, product2, product3 }
    };
    Order order2 = new Order
    {
        Customer = customer2,
        Products = new List<Product> { product4, product5, product6 }
    };
    Order order3 = new Order
    {
        Customer = customer3,
        Products = new List<Product> { product7, product8, product9, product10 }
    };
    db.Orders.AddRange(order1, order2, order3);

    db.SaveChanges();
}

using (ApplicationContext db = new ApplicationContext())
{
    // 1. Сортування продуктів за ціною
    var sortedProducts = db.Products.OrderBy(p => p.Price).ToList();
    Console.WriteLine("Tovaru posortovani za cinojy:");
    foreach (var product in sortedProducts)
    {
        Console.WriteLine($"{product.Name}: ${product.Price}");
    }

    // 2. Товари дорожчі за задану ціну
    double minPrice = 800.00;
    var expensiveProducts = db.Products.Where(p => p.Price > minPrice).ToList();
    Console.WriteLine($"Tovaru dorozhchi za ${minPrice}:");
    foreach (var product in expensiveProducts)
    {
        Console.WriteLine($"{product.Name}: ${product.Price}");
    }

    Console.WriteLine("\n");

    // 3. Замовлення із кількістю товарів у кожному
    var ordersWithProductCount = db.Orders
        .Select(o => new
        {
            o.Id,
            CustomerName = o.Customer.Name,
            ProductCount = o.Products.Count
        })
        .ToList();

    Console.WriteLine("Spusok zamovlen z kilkistiy tovariv: ");
    foreach (var order in ordersWithProductCount)
    {
        Console.WriteLine($"Order #{order.Id}, Pokypec: {order.CustomerName}, Tovaru: {order.ProductCount}");
    }

    Console.WriteLine("\n");

    // 4. Список унікальних клієнтів, які купили певний продукт
    string targetProductName = "iPhone 14";
    var customersWhoBoughtProduct = db.Orders
        .Where(o => o.Products.Any(p => p.Name == targetProductName))
        .Select(o => o.Customer)
        .Distinct()
        .ToList();

    Console.WriteLine($"Pokuptci, jaki prudbalu {targetProductName}: ");
    foreach (var customer in customersWhoBoughtProduct)
    {
        Console.WriteLine($"{customer.Name} ({customer.Email})");
    }

    Console.WriteLine("\n");

    // 5. Найдорожчий продукт
    var mostExpensiveProduct = db.Products.OrderByDescending(p => p.Price).FirstOrDefault();
    if (mostExpensiveProduct != null)
    {
        Console.WriteLine("Naidorozhchuj tovar: ");
        Console.WriteLine($"{mostExpensiveProduct.Name}: ${mostExpensiveProduct.Price}");
    }

    Console.WriteLine("\n");

    // 6. Виведення замовлень клієнта за його ім'ям
    string customerName = "John Doe";
    var ordersByCustomer = db.Orders
        .Where(o => o.Customer.Name == customerName)
        .Include(o => o.Products)
        .ToList();

    Console.WriteLine($"Zamovlennia dlia pokupcia: {customerName}");
    foreach (var order in ordersByCustomer)
    {
        Console.WriteLine($"Order #{order.Id}, Tovaru: ");
        foreach (var product in order.Products)
        {
            Console.WriteLine($"\t{product.Name}: ${product.Price}");
        }
    }
}
