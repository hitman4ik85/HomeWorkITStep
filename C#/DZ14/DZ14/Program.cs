
/*
//Task1
using System;

class Program
{
    public delegate int DelCountKratniSemu(int[] num);

    static void Main(string[] args)
    {
        Random rand = new Random();
        int[] num = new int[10];

        for (int i = 0; i < num.Length; i++)
        {
            num[i] = rand.Next(1, 101);
        }

        Console.Write("Mas: ");
        for (int i = 0; i < num.Length; i++)
        {
            Console.Write(num[i] + " ");
        }
        Console.WriteLine();

        DelCountKratniSemu kratniSemu = (int[] nums) =>
        {
            int count = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] % 7 == 0)
                {
                    count++;
                }
            }
            return count;
        };

        Console.WriteLine($"Kratni semu: {kratniSemu(num)}");
    }
}
*/



/*
//Task2
using System;

class Program
{
    public delegate int DelCountPozutuv(int[] num);

    static void Main(string[] args)
    {
        Random rand = new Random();
        int[] num = new int[10];

        for (int i = 0; i < num.Length; i++)
        {
            num[i] = rand.Next(-100, 101);
        }

        Console.Write("Mas: ");
        for (int i = 0; i < num.Length; i++)
        {
            Console.Write(num[i] + " ");
        }
        Console.WriteLine();

        DelCountPozutuv pozutuv = (int[] nums) =>
        {
            int count = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                {
                    count++;
                }
            }
            return count;
        };

        Console.WriteLine($"Pozutuvni: {pozutuv(num)}");
    }
}
*/