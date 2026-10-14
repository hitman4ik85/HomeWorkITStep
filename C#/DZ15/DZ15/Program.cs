//Task1
using System;

class Program
{
    static void Main(string[] args)
    {
        int[,] matrix = new int[5, 5];
        Random rand = new Random();

        var fill_array = (int[,] tmp_arr) =>
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    tmp_arr[i, j] = rand.Next(1, 100);
                }
            }
        };

        var bilshe_za_30 = (int[,] tmp_arr) =>
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (tmp_arr[i, j] < 30)
                    {
                        tmp_arr[i, j] = rand.Next(31, 100);
                    }
                }
            }
        };

        var ne_parni_chusla = (int[,] tmp_arr) =>
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (tmp_arr[i, j] % 2 == 0)
                    {
                        tmp_arr[i, j] += 1;
                    }
                }
            }
        };

        var show_array = (int[,] tmp_arr) =>
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    Console.Write(tmp_arr[i, j] + " ");
                }
                Console.WriteLine();
            }
        };

        fill_array(matrix);
        Console.WriteLine("Massuv:");
        show_array(matrix);

        bilshe_za_30(matrix);
        Console.WriteLine("\nMassuv bilshe za 30:");
        show_array(matrix);

        ne_parni_chusla(matrix);
        Console.WriteLine("\nMassuv ne parnuh chusel:");
        show_array(matrix);
    }
}