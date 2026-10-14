
//Task1
using System;

public delegate void OperationCompletedHandler(double num1, double num2, string oper, double rez);

class SimpleCalculator
{
    public event OperationCompletedHandler onOperationCompleted;

    public void Calculate(double num1, double num2, string oper)
    {
        if (num1 < 0 || num2 < 0)
        {
            throw new InvalidOperationException("Chusla povunni bytu dodatnimu!");
        }

        double rez = 0;

        switch (oper)
        {
            case "+":
                rez = num1 + num2;
                break;
            case "-":
                rez = num1 - num2;
                break;
            case "*":
                rez = num1 * num2;
                break;
            case "/":
                if (num2 == 0)
                {
                    throw new DivideByZeroException("Na 0 ne diletsa!");
                }
                rez = num1 / num2;
                break;
            default:
                throw new InvalidOperationException("Oberit pravulny dijy");
        }

        if (onOperationCompleted != null)
        {
            onOperationCompleted(num1, num2, oper, rez);
        }
    }
}

class Program
{
    static void OperationCompleted(double num1, double num2, string oper, double rez)
    {
        Console.WriteLine($"Rezult: {num1} {oper} {num2} = {rez}");
    }

    static void Main(string[] args)
    {
        SimpleCalculator calc = new SimpleCalculator();
        calc.onOperationCompleted += OperationCompleted;

        while (true)
        {
            try
            {
                Console.Write("Vvedit pershe chuslo: ");
                double num1 = Convert.ToDouble(Console.ReadLine());

                Console.Write("Vvedit druge chuslo: ");
                double num2 = Convert.ToDouble(Console.ReadLine());

                Console.Write("Vuberit ( +, -, *, / ): ");
                string oper = Console.ReadLine();

                calc.Calculate(num1, num2, oper);
            }
            catch (FormatException)
            {
                Console.WriteLine("Nekorektnui vvid");
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }

            string choice;
            do
            {
                Console.WriteLine("\nDali? (y-tak/n-ni)");
                choice = Console.ReadLine();
            } while (choice.ToLower() != "y" && choice.ToLower() != "n");

            if (choice.ToLower() != "y") break;
        }
    }
}
