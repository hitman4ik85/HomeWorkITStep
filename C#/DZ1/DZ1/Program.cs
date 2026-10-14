using System;
using System.Text;

Console.OutputEncoding = Encoding.UTF8;
Random rand = new Random();

Console.WriteLine("Гра: Кидання кубика.");

Console.Write("Введіть кількість кидків: ");
int countKudkiv = Convert.ToInt32(Console.ReadLine());

int playerSum = 0;
int computerSum = 0;

Console.WriteLine("\nКидає гравець:");

for (int i = 1; i <= countKudkiv; i++)
{
    int playerRoll = rand.Next(1, 7);
    playerSum += playerRoll;
    Console.WriteLine($"Кидок {i}: {playerRoll}");
}

Console.WriteLine("\nКидає комп'ютер:");

for (int i = 1; i <= countKudkiv; i++)
{
    int computerRoll = rand.Next(1, 7);
    computerSum += computerRoll;
    Console.WriteLine($"Кидок {i}: {computerRoll}");
}

Console.WriteLine($"\nЗагальна сума гравця: {playerSum}");
Console.WriteLine($"Загальна сума комп'ютера: {computerSum}");

if (playerSum > computerSum)
{
    Console.WriteLine("Ви перемогли!");
}
else if (playerSum < computerSum)
{
    Console.WriteLine("Комп'ютер переміг!");
}
else
{
    Console.WriteLine("Нічия!");
}