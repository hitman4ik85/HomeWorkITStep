using System;
using DZ1.Models;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        Console.OutputEncoding = Encoding.UTF8;
        Console.InputEncoding = Encoding.UTF8;

        while (true)
        {
            Console.WriteLine("Меню:");
            Console.WriteLine("1. Додати користувача");
            Console.WriteLine("2. Редагувати користувача");
            Console.WriteLine("3. Видалити користувача");
            Console.WriteLine("4. Переглянути всіх користувачів");
            Console.WriteLine("5. Вихід");
            Console.Write("Оберіть дію: ");

            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    AddUser();
                    break;
                case "2":
                    EditUser();
                    break;
                case "3":
                    DeleteUser();
                    break;
                case "4":
                    ViewAllUsers();
                    break;
                case "5":
                    return;
                default:
                    Console.WriteLine("Некоректний вибір. Спробуйте ще раз.");
                    break;
            }
        }
    }

    static void AddUser()
    {
        Console.Write("Введіть ім'я нового користувача: ");
        string? name = Console.ReadLine();

        Console.Write("Введіть вік нового користувача: ");
        int age = Convert.ToInt32(Console.ReadLine());

        using (var db = new ApplicationContext())
        {
            var user = new User { Name = name, Age = age };
            db.Users.Add(user);
            db.SaveChanges();
        }

        Console.WriteLine($"Користувача '{name}', {age} років, додано.");
    }

    static void EditUser()
    {
        Console.Write("Введіть ім'я користувача для редагування: ");
        string? name = Console.ReadLine();

        using (var db = new ApplicationContext())
        {
            var user = db.Users.FirstOrDefault(u => u.Name == name);
            if (user != null)
            {
                Console.Write("Введіть нове ім'я: ");
                string? newName = Console.ReadLine();

                Console.Write("Введіть новий вік: ");
                int newAge = Convert.ToInt32(Console.ReadLine());

                user.Name = newName;
                user.Age = newAge;
                db.SaveChanges();
                Console.WriteLine("Ім'я та вік користувача оновлено.");
            }
            else
            {
                Console.WriteLine("Користувача не знайдено.");
            }
        }
    }

    static void DeleteUser()
    {
        Console.Write("Введіть ім'я користувача для видалення: ");
        string? name = Console.ReadLine();

        using (var db = new ApplicationContext())
        {
            var user = db.Users.FirstOrDefault(u => u.Name == name);
            if (user != null)
            {
                db.Users.Remove(user);
                db.SaveChanges();
                Console.WriteLine("Користувача видалено.");
            }
            else
            {
                Console.WriteLine("Користувача не знайдено.");
            }
        }
    }

    static void ViewAllUsers()
    {
        using (var db = new ApplicationContext())
        {
            var users = db.Users.ToList();
            Console.WriteLine("Список користувачів:");
            foreach (var user in users)
            {
                Console.WriteLine($"ID: {user.Id}, Ім'я: {user.Name}, Вік: {user.Age}");
            }
        }
    }
}