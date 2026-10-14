using System;
using System.Collections.Generic;
using System.Threading;

namespace DZ3_1
{
    public class Program
    {
        static bool Chuslo(int num)
        {
            if (num < 2) return false;
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }

        static void GenChusel(int nuz_mezha, int verh_mezha)
        {
            List<int> chusla = new List<int>();
            for (int i = nuz_mezha; i <= verh_mezha; i++)
            {
                if (Chuslo(i))
                {
                    chusla.Add(i);
                    Console.WriteLine($"{i}");
                    Thread.Sleep(200);
                }
            }
        }

        static void Main(string[] args)
        {
            Console.Write("Vvedit nuzhnjy mezhy (abo prosto Enter): ");
            string nuz = Console.ReadLine();
            int nuz_mezha = string.IsNullOrEmpty(nuz) ? 2 : Convert.ToInt32(nuz);

            Console.Write("Vvedit verhnjy mezhy (abo prosto Enter): ");
            string verh = Console.ReadLine();
            int verh_mezha = string.IsNullOrEmpty(verh) ? int.MaxValue : Convert.ToInt32(verh);

            Thread pT = new Thread(() => GenChusel(nuz_mezha, verh_mezha));
            pT.Start();
        }
    }
}
