//Task1
using System;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        string filePath = "D:\\IT Step Shag\\PK Kurs\\C#\\DZ\\DZ16\\DZ16\\Fibonachi.txt";

        Console.Write("Vvestu chuslo do jakogo: ");
        int chuslo = Convert.ToInt32(Console.ReadLine());

        using (FileStream fs = new FileStream(filePath, FileMode.Create))
        {
            using (StreamWriter sw = new StreamWriter(fs))
            {
                int a = 1; 
                int b = 1;
                sw.WriteLine(a); 
                while (b <= chuslo)
                {
                    sw.WriteLine(b);
                    int newNumber = a + b;
                    a = b;
                    b = newNumber;
                }
            }
        }

        using (StreamReader sr = new StreamReader(filePath))
        {
            Console.WriteLine("\nChusla Fibonachi do " + chuslo + ":");
            Console.WriteLine(sr.ReadToEnd());
        }
    }
}