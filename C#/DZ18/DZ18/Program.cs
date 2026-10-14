//Task1
using System;
using System.Text.RegularExpressions;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Vvedit email: ");
        string userInput = Console.ReadLine();

        string pattern = @"^(?!.*[._-]{2})(?![.-])[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+)*@[a-zA-Z0-9-]+(?:\.[a-zA-Z]{2,})+$";

        Regex regex = new Regex(pattern);

        if (regex.IsMatch(userInput))
        {
            Console.WriteLine("Email vvedeno korektno");
        }
        else
        {
            Console.WriteLine("Email vvedeno ne korektno");
        }
    }
}

//^(?!.*[._-]{2}) - чи нема підряд ._-
//(?![.-]) - чи не починається e-mail з . або -
//[a-zA-Z0-9!#$%&'*+/=?^_{|}~-]+ - літери, цифри та спеціальні символи перед @
//(?:\.[a-zA-Z0-9!#$%&'*+/=?^_{|}~-]+)*` - може мати крапки та далі допустимі символи
//@[a-zA-Z0-9-] + - після @ обов'язково йде тільки домен
//(?:\.[a-zA-Z] { 2,})+$ - домен може закінчуватися на крапку та літери (наприклад: .com) + закінчення рядка

//string pattern = @"^[a-zA-Z0-9]+@[a-zA-Z]+\.[a-zA-Z]{2,}$"; - ось спрощений варіант