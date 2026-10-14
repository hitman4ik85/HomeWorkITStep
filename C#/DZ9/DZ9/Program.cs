//Task1
using System;

class SpusokKnug
{
    private string[] knugu = new string[10];

    public string this[int index]
    {
        get
        {
            if (index < 0 || index >= knugu.Length)
                throw new IndexOutOfRangeException("Nekorektnui indeks.");
            return knugu[index] ?? " ";
        }
        set
        {
            if (index < 0 || index >= knugu.Length)
                throw new IndexOutOfRangeException("Nekorektnui indeks.");
            knugu[index] = value ?? throw new ArgumentNullException("Nazva knugu ne mozhe bytu pystojy.");
        }
    }

    public static SpusokKnug operator +(SpusokKnug spusok, string knuga)
    {
        for (int i = 0; i < spusok.knugu.Length; i++)
        {
            if (spusok.knugu[i] == null)
            {
                spusok.knugu[i] = knuga;
                return spusok;
            }
        }
        throw new InvalidOperationException("Spusok zapovneno.");
    }

    public static SpusokKnug operator -(SpusokKnug spusok, string knuga)
    {
        for (int i = 0; i < spusok.knugu.Length; i++)
        {
            if (spusok.knugu[i] == knuga)
            {
                spusok.knugu[i] = null;
                return spusok;
            }
        }
        throw new InvalidOperationException("Knugy ne znajdeno.");
    }

    public string KnuguZaIndexom(int index)
    {
        if (index < 0 || index >= knugu.Length)
            throw new IndexOutOfRangeException("Nekorektnui indeks.");
        return knugu[index] ?? " ";
    }

    public bool KnuguZaNazvojy(string knuga)
    {
        for (int i = 0; i < knugu.Length; i++)
        {
            if (knugu[i] == knuga)
                return true;
        }
        return false;
    }
}

class Program
{
    static void Main(string[] args)
    {
        SpusokKnug spusok = new SpusokKnug();

        Console.WriteLine("Dodano knugy 'Harri Potter' do spusky.");
        spusok += "Harri Potter";
        Console.WriteLine("Dodano knugy 'Volodar Persntiv' do spusky.");
        spusok += "Volodar Perstniv";

        Console.WriteLine("\nPoshyk knugu za nazvojy 'Harri Potter':");
        Console.WriteLine($"Chu e knuga 'Harri Potter'? - {spusok.KnuguZaNazvojy("Harri Potter")}");

        Console.WriteLine("\nPoshyk knugu za indeksom:");
        Console.WriteLine($"Knuga na indeksi 0: {spusok[0]}");
        Console.WriteLine($"Knuga na indeksi 1: {spusok[1]}");
        Console.WriteLine($"Knuga na indeksi 2: {spusok[2]}");

        Console.WriteLine("\nVudaljaemo knugy 'Harri Potter' zi spusky.");
        spusok -= "Harri Potter";

        Console.WriteLine("\nPoshyk knugu za nazvojy 'Harri Potter' pislja vudalennja:");
        Console.WriteLine($"Chu e knuga 'Harri Potter'? - {spusok.KnuguZaNazvojy("Harri Potter")}");

        Console.WriteLine("\nPoshyk knugu za indeksom pislja vudalennja:");
        Console.WriteLine($"Knyga na indeksi 0: {spusok[0]}");

        Console.WriteLine("\nDodaemo knugy 'Zhanna Dark' do spusky.");
        spusok += "Zhanna Dark";

        Console.WriteLine("\nPoshyk knugu za indeksom pislja dodavannja 'Zhanna Dark':");
        Console.WriteLine($"Knyga na indeksi 0: {spusok.KnuguZaIndexom(0)}");
        Console.WriteLine($"Knyga na indeksi 1: {spusok.KnuguZaIndexom(1)}");
        Console.WriteLine($"Knyga na indeksi 2: {spusok.KnuguZaIndexom(2)}");
    }
}
