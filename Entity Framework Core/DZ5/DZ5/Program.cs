
using Microsoft.EntityFrameworkCore;
using DZ5;
using DZ5.Models;

class Program
{
    static void MainMenu()
    {
        while (true)
        {
            Console.WriteLine("\nГоловне меню:");
            Console.WriteLine("1 - Користувач");
            Console.WriteLine("2 - Адмiнiстратор");
            Console.WriteLine("3 - Вийти");

            string choice = Console.ReadLine() ?? string.Empty;

            if (choice == "1")
            {
                using (ApplicationContext db = new ApplicationContext())
                {
                    UserMenu(db);
                }
            }
            else if (choice == "2")
            {
                if (AdminLogin())
                {
                    using (ApplicationContext db = new ApplicationContext())
                    {
                        AdminMenu(db);
                    }
                }
            }
            else if (choice == "3")
            {
                break;
            }
            else
            {
                Console.WriteLine("Невiрний вибiр!");
            }
        }
    }

    static bool AdminLogin()
    {
        Console.WriteLine("Введiть логiн:");
        string login = Console.ReadLine() ?? string.Empty;

        Console.WriteLine("Введiть пароль:");
        string password = string.Empty;
        ConsoleKeyInfo key;
        do
        {
            key = Console.ReadKey(intercept: true);
            if (key.Key == ConsoleKey.Backspace && password.Length > 0)
            {
                password = password[0..^1];
                Console.Write("\b \b");
            }
            else if (!char.IsControl(key.KeyChar))
            {
                password += key.KeyChar;
                Console.Write("*");
            }
        } while (key.Key != ConsoleKey.Enter);
        Console.WriteLine();

        if (login == "admin" && password == "admin")
        {
            Console.WriteLine("Успiшний вхiд адмiнiстратора!");
            return true;
        }
        else
        {
            Console.WriteLine("Невiрний логiн або пароль!");
            return false;
        }
    }

    static void AdminMenu(ApplicationContext db)
    {
        while (true)
        {
            Console.WriteLine("\nМеню адмiнiстратора:");
            Console.WriteLine("1 - Змiнити кiлькiсть лiтрiв на колонцi");
            Console.WriteLine("2 - Змiнити цiну за лiтр");
            Console.WriteLine("3 - Вийти з панелi адмiнiстратора");

            string choice = Console.ReadLine() ?? string.Empty;

            if (choice == "1")
            {
                Console.WriteLine("Введiть ID колонки:");
                int pointId = int.Parse(Console.ReadLine()!);
                GazStationPoint? point = db.GazStationPoints.FirstOrDefault(p => p.Id == pointId);
                if (point == null)
                {
                    Console.WriteLine("Колонку не знайдено!");
                    continue;
                }

                Console.WriteLine($"Поточна кiлькiсть: {point.CurrentFuel} л. Введiть нову кiлькiсть:");
                point.CurrentFuel = double.Parse(Console.ReadLine()!);
                db.SaveChanges();
                Console.WriteLine("Кiлькiсть оновлено успiшно!");
            }
            else if (choice == "2")
            {
                Console.WriteLine("Введiть ID колонки:");
                int pointId = int.Parse(Console.ReadLine()!);
                GazStationPoint? point = db.GazStationPoints.FirstOrDefault(p => p.Id == pointId);
                if (point == null)
                {
                    Console.WriteLine("Колонку не знайдено!");
                    continue;
                }

                Console.WriteLine($"Поточна цiна: {point.PricePerLiter} грн/л. Введiть нову цiну:");
                point.PricePerLiter = double.Parse(Console.ReadLine()!);
                db.SaveChanges();
                Console.WriteLine("Цiну оновлено успiшно!");
            }
            else if (choice == "3")
            {
                break;
            }
            else
            {
                Console.WriteLine("Невiрний вибiр!");
            }
        }
    }

        static void UserMenu(ApplicationContext db)
    {
        while (true)
        {
            Console.WriteLine("\nСписок користувачiв: ");
            var users = db.Users.Include(u => u.Location).ToList();
            foreach (var user in users)
            {
                Console.WriteLine($"ID: {user.Id}, Iм'я: {user.Name}, Мiсто: {user.Location.City}, Баланс: {user.Balance} грн.");
            }

            Console.WriteLine("\nМеню користувача: ");
            Console.WriteLine("1 - Заправитись");
            Console.WriteLine("2 - Переглянути статистику");
            Console.WriteLine("3 - Повернутись до головного меню");

            string choice = Console.ReadLine() ?? string.Empty;

            if (choice == "1")
            {
                try
                {
                    Console.WriteLine("Введiть ID користувача:");
                    int userId = int.Parse(Console.ReadLine()!);
                    User user = db.Users.Include(u => u.Transactions).Include(u => u.Location).FirstOrDefault(u => u.Id == userId)
                        ?? throw new Exception("Користувача не знайдено!");

                    Console.WriteLine("Введiть ID колонки:");
                    int pointId = int.Parse(Console.ReadLine()!);
                    GazStationPoint? point = db.GazStationPoints.Include(p => p.GazStation).ThenInclude(gs => gs.Location)
                        .FirstOrDefault(p => p.Id == pointId)
                        ?? throw new Exception("Колонку не знайдено!");

                    Console.WriteLine($"\nIнформацiя про колонку: ");
                    Console.WriteLine($"- ID колонки: {point.Id}");
                    Console.WriteLine($"- Мiсце: {point.GazStation.Location.City}, {point.GazStation.Location.Address}");
                    Console.WriteLine($"- Поточний запас палива: {point.CurrentFuel} л.");
                    Console.WriteLine($"- Цiна за один лiтр: {point.PricePerLiter} грн.");

                    Console.WriteLine("\nВведiть кiлькiсть лiтрiв для покупки:");
                    double liters = double.Parse(Console.ReadLine()!);

                    if (liters > point.CurrentFuel)
                        throw new Exception("На колонцi немає достатньо палива!");

                    double cost = liters * point.PricePerLiter;
                    if (user.Balance < cost)
                        throw new Exception("У вас недостатньо коштiв!");

                    user.Balance -= cost;
                    point.CurrentFuel -= liters;

                    GazStationTransaction transaction = new GazStationTransaction
                    {
                        User = user,
                        GazStationPoint = point,
                        Amount = liters,
                        TotalCost = cost
                    };

                    db.Transactions.Add(transaction);
                    db.SaveChanges();

                    Console.WriteLine("Операцiю завершено успiшно!");
                    Console.WriteLine($"\nВи купили {liters} л. за {cost} грн. Залишок: {user.Balance} грн.");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Помилка: {ex.Message}");
                }
            }
            else if (choice == "2")
            {
                Console.WriteLine("\nСтатистика транзакцiй: ");
                var transactions = db.Transactions.Include(t => t.User).Include(t => t.GazStationPoint).ThenInclude(p => p.GazStation);
                foreach (var t in transactions)
                {
                    Console.WriteLine($"{t.User.Name} заправився на {t.Amount} л. за {t.TotalCost} грн. на {t.GazStationPoint.GazStation.Name}");
                }
            }
            else if (choice == "3")
            {
                break;
            }
            else
            {
                Console.WriteLine("Невiрний вибiр!");
            }
        }
    }
    static void Main(string[] args)
    {
        using (ApplicationContext db = new ApplicationContext())
        {
            DatabaseInitializer.Initialize(db);
        }

        MainMenu();
    }
}
