//Task1
using System.Text;

Console.OutputEncoding = Encoding.UTF8;
Random rand = new Random();

int[,] my_arr = new int[7, 7];

for (int i = 0; i < 7; i++)
{
    for (int j = 0; j < 7; j++)
    {
        my_arr[i, j] = rand.Next(1, 101);
    }
}

Console.WriteLine("Масив:");
for (int i = 0; i < 7; i++)
{
    for (int j = 0; j < 7; j++)
    {
        Console.Write(my_arr[i, j] + "\t");
    }
    Console.WriteLine();
}

int minElement = my_arr[0, 0];
int maxElement = my_arr[0, 0];

for (int i = 0; i < 7; i++)
{
    for (int j = 0; j < 7; j++)
    {
        if (my_arr[i, j] < minElement)
        {
            minElement = my_arr[i, j];
        }
        if (my_arr[i, j] > maxElement)
        {
            maxElement = my_arr[i, j];
        }
    }
}

Console.WriteLine($"\nМінімальний елемент масиву: {minElement}");
Console.WriteLine($"Максимальний елемент масиву: {maxElement}\n");

for (int i = 0; i < 7; i++)
{
    int rowMin = my_arr[i, 0];
    int rowMax = my_arr[i, 0];

    for (int j = 1; j < 7; j++)
    {
        if (my_arr[i, j] < rowMin)
        {
            rowMin = my_arr[i, j];
        }
        if (my_arr[i, j] > rowMax)
        {
            rowMax = my_arr[i, j];
        }
    }

    Console.WriteLine($"Рядок {i + 1}: Мін = {rowMin}, Макс = {rowMax}");
}



/*//Task2
using System.Text;

Console.OutputEncoding = Encoding.UTF8;
int[] numbers = new int[4];

Console.WriteLine("Введіть 4 числа:");
for (int i = 0; i < 4; i++)
{
    Console.Write($"Число {i + 1}: ");
    numbers[i] = Convert.ToInt32(Console.ReadLine());
}

if (numbers[0] == numbers[3] && numbers[1] == numbers[2])
{
    Console.WriteLine("Масив є паліндромом.");
}
else
{
    Console.WriteLine("Масив не є паліндромом.");
}*/