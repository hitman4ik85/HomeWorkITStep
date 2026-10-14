using System;

namespace my
{
    class Program
    {
        public delegate void Action(int[] num);

        static int[] fullMas(int SIZE)
        {
            Random random = new Random();
            int[] num = new int[SIZE];

            for (int i = 0; i < SIZE; i++)
            {
                num[i] = random.Next(1, 101);
            }

            return num;
        }

        static void showMas(int[] num)
        {
            Console.Write("Masuv: ");
            for (int i = 0; i < num.Length; i++)
            {
                Console.Write(num[i] + " ");
            }
            Console.WriteLine();
        }

        static void avrMas(int[] num)
        {
            double sum = 0;
            for (int i = 0; i < num.Length; i++)
            {
                sum += num[i];
            }
            double avr = sum / num.Length;
            Console.WriteLine("Average: " + avr);
        }

        static void Main(string[] args)
        {
            int size = 10;
            int[] num = fullMas(size);

            Action actionMas = showMas;
            Action actionAvr = avrMas;

            actionMas(num);
            actionAvr(num);
        }
    }
}