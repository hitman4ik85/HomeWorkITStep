//Task1
Random rand = new Random();

int[][] myMass5 = new int[5][];

for (int i = 0; i < myMass5.Length; i++)
{
    myMass5[i] = new int[rand.Next(3, 8)];
    for (int j = 0; j < myMass5[i].Length; j++)
    {
        myMass5[i][j] = rand.Next(0, 101);
    }
}

Console.WriteLine("Pochatkovij masiv:");
for (int i = 0; i < myMass5.Length; i++)
{
    for (int j = 0; j < myMass5[i].Length; j++)
    {
        Console.Write(myMass5[i][j] + " ");
    }
    Console.WriteLine();
}

int sum = 0;
int count = 0;

for (int i = 0; i < myMass5.Length; i++)
{
    for (int j = 0; j < myMass5[i].Length; j++)
    {
        sum += myMass5[i][j];
        count++;
    }
}

int seredne = count > 0 ? sum / count : 0;
Console.WriteLine($"\nSeredne znachennia: {seredne}");

int kilkistChiselBilshe = 0;
Console.WriteLine("\nChisla bilshi za seredne znachennia:");
for (int i = 0; i < myMass5.Length; i++)
{
    Console.Write($"Pidmas {i + 1}: ");
    bool poshykChisel = false;
    for (int j = 0; j < myMass5[i].Length; j++)
    {
        if (myMass5[i][j] > seredne)
        {
            Console.Write(myMass5[i][j] + " ");
            poshykChisel = true;
            kilkistChiselBilshe++;
        }
    }
    if (!poshykChisel)
    {
        Console.Write("Nema chisel bilshuh za seredne.");
    }
    Console.WriteLine();
}

Console.WriteLine($"\nKilkist chisel bilshe za seredne: {kilkistChiselBilshe}");