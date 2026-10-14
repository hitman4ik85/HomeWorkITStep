//Task1

using System;

class BankAcID
{
    private int balance;

    public BankAcID(int eBalance)
    {
        balance = eBalance;
    }

    public void ZnatieKesh(int sum)
    {
        try
        {
            if (sum > balance)
            {
                throw new InvalidOperationException("Nemae koshtiv na rahynky.");
            }
            balance -= sum;
            Console.WriteLine($"Vu znjalu {sum}$. Vash rahynok: {balance}$");
        }
        catch (InvalidOperationException ex)
        {
            Console.WriteLine($"Exception: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Program is ended.");
        }
    }

    public void ShowBalance()
    {
        Console.WriteLine($"Vash rahynok: {balance}$");
    }
}

class Program
{
    static void Main(string[] args)
    {
        BankAcID userID = new BankAcID(10000);
        userID.ShowBalance();

        Console.Write("Vvedit sumy dlja znatia: ");
        int sum = Convert.ToInt32(Console.ReadLine());
        userID.ZnatieKesh(sum);
    }
}




/*//Task2

using System;

class LoginInputException : Exception
{
    public LoginInputException(string message) : base(message) { }
}
class PassInputException : Exception
{
    public PassInputException(string message) : base(message) { }
}

class Program
{
    public void Perevirka(string log, string pass)
    {
        try
        {
            if (log != "qwerty")
            {
                throw new LoginInputException("Nevirnui login.");
            }

            if (pass != "qwerty")
            {
                throw new PassInputException("Nevirnui parol.");
            }

            Console.WriteLine("Vu avtoruzovani!");
        }
        catch (LoginInputException ex)
        {
            Console.WriteLine($"Exception: {ex.Message}");
        }
        catch (PassInputException ex)
        {
            Console.WriteLine($"Exception: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Program is ended.");
        }
    }

    static void Main(string[] args)
    {
        Program userID = new Program();

        Console.Write("Vvedit login: ");
        string log = Console.ReadLine();

        Console.Write("Vvenit parol: ");
        string pass = Console.ReadLine();

        userID.Perevirka(log, pass);
    }
}*/



/*//Task3
using System;

class Person
{
    private int id;
    private string name;
    private string lastName;
    private int age;
    private string studyOrWork;

    public Person(int id, string name, string lastName, int age, string studyOrWork)
    {
        this.id = id;
        this.name = name;
        this.lastName = lastName;
        this.age = age;
        this.studyOrWork = studyOrWork;
    }

    public Person(int id, string name, string lastName, int age)
    {
        this.id = id;
        this.name = name;
        this.lastName = lastName;
        this.age = age;
    }

    public Person(string name, string lastName, int age)
    {
        this.name = name;
        this.lastName = lastName;
        this.age = age;
    }

    public Person(int id, string name, string lastName)
    {
        this.id = id;
        this.name = name;
        this.lastName = lastName;
    }

    public Person(int id, string name)
    {
        this.id = id;
        this.name = name;
    }

    public void ShowInfo()
    {
        Console.Write($"Name: {name}");

        if (!string.IsNullOrEmpty(lastName))
        {
            Console.Write($", Last Name: {lastName}");
        }

        if (age != 0)
        {
            Console.Write($", Age: {age}");
        }

        if (id != 0)
        {
            Console.Write($", ID: {id}");
        }

        if (!string.IsNullOrEmpty(studyOrWork))
        {
            Console.Write($", Study/Work: {studyOrWork}");
        }

        Console.WriteLine();
    }
}

class Program
{
    static void Main(string[] args)
    {
        Person user1 = new Person(1, "John", "Doe", 25, "Study");
        user1.ShowInfo();

        Person user2 = new Person(2, "Karlo", "Litvin", 31);
        user2.ShowInfo();

        Person user3 = new Person("Pamela", "Jemison", 42);
        user3.ShowInfo();

        Person user4 = new Person(4, "Bob", "Smith");
        user4.ShowInfo();

        Person user5 = new Person(5, "Karolina");
        user5.ShowInfo();
    }
}*/