//Task1
using System;
class MyzuchnuiInstryment
{
    public string name;

    public MyzuchnuiInstryment(string name)
    {
        this.name = name;
    }

    public void Show()
    {
        Console.WriteLine($"Nazva: {name}");
    }
}

class Skrupka : MyzuchnuiInstryment
{
    public Skrupka(string name) : base(name) { }

    public void Sound()
    {
        Console.WriteLine($"{name} vudae zvyk.");
    }

    public void Desc()
    {
        Console.WriteLine($"{name} - ce 4-strynnui myzuchnuj instryment.");
    }

    public void History()
    {
        Console.WriteLine($"{name}: vpershe byla stvorena v Italii.");
    }
}

class Trombon : MyzuchnuiInstryment
{
    public Trombon(string name) : base(name) { }

    public void Sound()
    {
        Console.WriteLine($"{name} vudae potyzhnuj zvyk.");
    }

    public void Desc()
    {
        Console.WriteLine($"{name} - ce dyhovnuj instryment.");
    }

    public void History()
    {
        Console.WriteLine($"{name}: vpershe byv stvorenui v Evropi.");
    }
}

class Ykylele : MyzuchnuiInstryment
{
    public Ykylele(string name) : base(name) { }

    public void Sound()
    {
        Console.WriteLine($"{name} vudae legkuj zvyk.");
    }

    public void Desc()
    {
        Console.WriteLine($"{name} — ce malenkui strynnui instryment.");
    }

    public void History()
    {
        Console.WriteLine($"{name}: vpershe bylo stvoreno na Gavajah.");
    }
}

class Violonchel : MyzuchnuiInstryment
{
    public Violonchel(string name) : base(name) { }

    public void Sound()
    {
        Console.WriteLine($"{name} vudae glubokuj zvyk.");
    }

    public void Desc()
    {
        Console.WriteLine($"{name} — ce velukuj strynnui instryment.");
    }

    public void History()
    {
        Console.WriteLine($"{name}: vpershe byla stvorena v Italii.");
    }
}

class Program
{
    public static void Main(string[] args)
    {
        Skrupka skrupka = new Skrupka("Skrupka");
        skrupka.Show();
        skrupka.Sound();
        skrupka.Desc();
        skrupka.History();

        Console.WriteLine();
        Trombon trombon = new Trombon("Trombon");
        trombon.Show();
        trombon.Sound();
        trombon.Desc();
        trombon.History();

        Console.WriteLine();
        Ykylele ykylele = new Ykylele("Ykylele");
        ykylele.Show();
        ykylele.Sound();
        ykylele.Desc();
        ykylele.History();

        Console.WriteLine();
        Violonchel violonchel = new Violonchel("Violonchel");
        violonchel.Show();
        violonchel.Sound();
        violonchel.Desc();
        violonchel.History();
    }
}



/*//Task2

using System;

class Money
{
    public int Dollars;
    public int Cents;

    public Money() { }

    public Money(int dollars)
    {
        this.Dollars = dollars;
        this.Cents = 0;
    }

    public Money(int dollars, int cents)
    {
        this.Dollars = dollars;
        this.Cents = cents;
        BalanceDollarCents();
    }

    private void BalanceDollarCents()
    {
        Dollars += Cents / 100;
        Cents %= 100;
        if (Cents < 0)
        {
            Dollars -= 1;
            Cents += 100;
        }
    }

    public void ShowMoney()
    {
        Console.WriteLine($"Zagalna Syma: {Dollars} $ and {Cents} cents");
    }
}

class Product : Money
{
    public string Name;

    public Product() { }

    public Product(string name) : base()
    {
        this.Name = name;
    }

    public Product(string name, int dollars, int cents) : base(dollars, cents)
    {
        this.Name = name;
    }

    public void ZmenshennjaPrice(int dollars, int cents)
    {
        int totalCents = (Dollars * 100 + Cents) - (dollars * 100 + cents);
        if (totalCents < 0) totalCents = 0;
        (Dollars, Cents) = (totalCents / 100, totalCents % 100);
    }

    public void ShowProductInfo()
    {
        Console.WriteLine($"Product: {Name}, Price: {Dollars} $ and {Cents} cents");
    }
}

class Program
{
    public static void Main(string[] args)
    {
        Money money = new Money(2350, 35);
        money.ShowMoney();

        Product product = new Product("Ipad", 500, 50);
        product.ShowProductInfo();

        product.ZmenshennjaPrice(50, 25);
        Console.WriteLine("Cina pislja zmenshennja:");
        product.ShowProductInfo();
    }
}*/