
//Task1
using System;
class Rectangle
{
    public int shuruna;
    public int dovzhuna;

    public Rectangle(int shuruna, int dovzhuna)
    {
        this.shuruna = shuruna;
        this.dovzhuna = dovzhuna;
    }

    public int Plosha()
    {
        return shuruna * dovzhuna;
    }

    public int Perumetr()
    {
        return 2 * (shuruna + dovzhuna);
    }

    public void ShowInfo()
    {
        Console.WriteLine($"Prjamokytnuk, shurunojy {shuruna} sm, ta dovzhunojy {dovzhuna} sm");
    }
}

class Program
{
    public static void Main(string[] args)
    {
        Console.Write("Shuruna: ");
        int shuruna = Convert.ToInt32(Console.ReadLine());
        Console.Write("Dovzhuna: ");
        int dovzhuna = Convert.ToInt32(Console.ReadLine());

        Rectangle rectangle = new Rectangle(shuruna, dovzhuna);

        rectangle.ShowInfo();
        Console.WriteLine($"Plosha priamokytnuka: {rectangle.Plosha()} sm");
        Console.WriteLine($"Perumetr priamokytnuka: {rectangle.Perumetr()} sm");
    }
}




/*//Task2
using System;
class BankAccount
{
    public string name;
    public int accountNumber;
    public int balance;

    public BankAccount(string name, int accountNumber)
    {
        this.name = name;
        this.accountNumber = accountNumber;
        this.balance = 1000;
    }

    public void AddKesh(int sum)
    {
        if (sum > 0)
        {
            balance += sum;
            Console.WriteLine($"Dodana suma: {sum}$. Potochnuj balans: {balance}$");
        }
    }

    public void ZnjatuKesh(int sum)
    {
        if (sum > balance)
        {
            Console.WriteLine("Nedostatno koshtiv!");
        }
        else if (sum > 0)
        {
            balance -= sum;
            Console.WriteLine($"Znjato: {sum}$. Zalushok: {balance}$");
        }
    }

    public void ShowAccountInfo()
    {
        Console.WriteLine($"Name: {name}, Account Number: {accountNumber}, Balance: {balance}$");
    }
}

class Program
{
    public static void Main(string[] args)
    {
        BankAccount user = new BankAccount("Roman", 354);

        user.ShowAccountInfo();
        user.AddKesh(500);
        user.ZnjatuKesh(200);
        user.ZnjatuKesh(1500);
    }
}*/