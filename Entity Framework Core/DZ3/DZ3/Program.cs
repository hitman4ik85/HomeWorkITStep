using DZ3.Models;
using Microsoft.EntityFrameworkCore;

Console.WriteLine("Start Program");

using (ApplicationContext db = new ApplicationContext())
{
    var products = db.Products.ToList();
    Console.WriteLine("Products:");
    foreach (var product in products)
    {
        Console.WriteLine($"{product.ProductName} - {product.Manufacturer} - {product.Price}");
    }

    var customers = db.Customers.ToList();
    Console.WriteLine("\nCustomers:");
    foreach (var customer in customers)
    {
        Console.WriteLine($"{customer.FirstName}");
    }

    var orders = db.Orders.Include(o => o.Product).Include(o => o.Customer).ToList();
    Console.WriteLine("\nOrders:");
    foreach (var order in orders)
    {
        Console.WriteLine($"Customer: {order.Customer?.FirstName}, Product: {order.Product?.ProductName}, Count: {order.ProductCount}, Price: {order.Price}, Date: {order.CreatedAt.ToShortDateString()}");
    }
}
