using System;
using System.Collections.Generic;
using DZ2.Models;

Console.WriteLine("Start program");

using (ApplicationContext db = new ApplicationContext())
{
    List<User> users = new List<User>();

    while (true)
    {
        Console.Write("Enter name: ");
        var name = Console.ReadLine();
        Console.Write("Enter age: ");
        var age = Convert.ToInt32(Console.ReadLine());

        users.Add(new User { Name = name, Age = age });

        Console.Write("Add new user? Y or N: ");
        var anw = Console.ReadLine();
        if (anw != null && anw.ToLower().StartsWith("n"))
        {
            break;
        }
    }

    db.Users.AddRange(users);
    db.SaveChanges();

    Console.WriteLine("Users have been added to the database:");
    foreach (var user in db.Users)
    {
        Console.WriteLine($"{user.Name} - {user.Age} with id {user.Id}");
    }
}