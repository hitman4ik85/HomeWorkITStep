using DZ4.Models;
using Microsoft.EntityFrameworkCore;

void ShowMenu()
{
    Console.WriteLine("\n--- Menu ---");
    Console.WriteLine("1. Dodatu User");
    Console.WriteLine("2. Zminutu User");
    Console.WriteLine("3. Delete User");
    Console.WriteLine("4. Show All Users");
    Console.WriteLine("5. Exit");
    Console.Write("Vuberit option: ");
}

void AddUser()
{
    using (ApplicationContext db = new ApplicationContext())
    {
        Console.Write("Vvedit Login: ");
        string login = Console.ReadLine()!;
        Console.Write("Vvedit Password: ");
        string password = Console.ReadLine()!;
        Console.Write("Vvedit Name: ");
        string name = Console.ReadLine()!;
        Console.Write("Vvedit Age: ");
        int age = Convert.ToInt32(Console.ReadLine()!);

        User newUser = new User { Login = login, Password = password };
        UserProfile newProfile = new UserProfile { Name = name, Age = age, User = newUser };

        db.Users.Add(newUser);
        db.UserProfiles.Add(newProfile);
        db.SaveChanges();

        Console.WriteLine("Usera dodano!");
    }
}

void EditUser()
{
    using (ApplicationContext db = new ApplicationContext())
    {
        Console.Write("Vvedit Login: ");
        string login = Console.ReadLine()!;
        Console.Write("Vvedit Password: ");
        string password = Console.ReadLine()!;

        User? user = db.Users.Include(u => u.Profile).FirstOrDefault(u => u.Login == login && u.Password == password);
        if (user != null)
        {
            Console.WriteLine($"Zmina Usera: {user.Profile?.Name}");
            Console.Write("Vvedit new Name: ");
            user.Profile!.Name = Console.ReadLine()!;
            Console.Write("Vvedit new Age: ");
            user.Profile.Age = int.Parse(Console.ReadLine()!);
            Console.Write("Vvedit new Password: ");
            user.Password = Console.ReadLine()!;

            db.SaveChanges();
            Console.WriteLine("Usera zmineno!");
        }
        else
        {
            Console.WriteLine("Usera ne znaideno abo nevirnui password.");
        }
    }
}

void DeleteUser()
{
    using (ApplicationContext db = new ApplicationContext())
    {
        Console.Write("Vvedit Login: ");
        string login = Console.ReadLine()!;
        Console.Write("Vvedit Password: ");
        string password = Console.ReadLine()!;

        User? user = db.Users.Include(u => u.Profile).FirstOrDefault(u => u.Login == login && u.Password == password);
        if (user != null)
        {
            db.Users.Remove(user);
            db.SaveChanges();
            Console.WriteLine("Usera vudaleno!");
        }
        else
        {
            Console.WriteLine("Usera ne znaideno abo nevirnui password.");
        }
    }
}

void ShowAllUsers()
{
    using (ApplicationContext db = new ApplicationContext())
    {
        var users = db.Users.Include(u => u.Profile).ToList();
        Console.WriteLine("\n--- All Users ---");
        foreach (var user in users)
        {
            Console.WriteLine($"Name: {user.Profile?.Name}, Age: {user.Profile?.Age}, Login: {user.Login}, Password: {user.Password}");
        }
    }
}

// Сама програма
using (ApplicationContext db = new ApplicationContext())
{
    db.Database.EnsureDeleted();
    db.Database.EnsureCreated();

    User user1 = new User { Login = "Login1", Password = "pass123" };
    User user2 = new User { Login = "Login2", Password = "pass123" };

    UserProfile profile1 = new UserProfile { Age = 22, Name = "Tom", User = user1 };
    UserProfile profile2 = new UserProfile { Age = 32, Name = "Alice", User = user2 };
    db.UserProfiles.AddRange(profile1, profile2);
    db.SaveChanges();
}

while (true)
{
    ShowMenu();
    int option = Convert.ToInt32(Console.ReadLine()!);
    switch (option)
    {
        case 1:
            AddUser();
            break;
        case 2:
            EditUser();
            break;
        case 3:
            DeleteUser();
            break;
        case 4:
            ShowAllUsers();
            break;
        case 5:
            Console.WriteLine("Exit program...");
            return;
        default:
            Console.WriteLine("Invalid option. Please try again.");
            break;
    }
}