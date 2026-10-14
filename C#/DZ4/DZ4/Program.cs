//Task1

string VvidUsera()
{
    Console.WriteLine("Vvedit ryadok:");
    return Console.ReadLine();
}

string ObernenijRyadok(string vvid)
{
    if (string.IsNullOrEmpty(vvid))
    {
        return "Ryadok pustij abo null";
    }

    string revers = "";

    for (int i = vvid.Length - 1; i >= 0; i--)
    {
        revers += vvid[i];
    }

    return revers;
}

Console.WriteLine($"Obernenij ryadok: {ObernenijRyadok(VvidUsera())}");



/*//Task2
string VvidUsera()
{
    Console.WriteLine("Vvedit ryadok:");
    return Console.ReadLine();
}

string PershaLiteraZagolovna(string vvid)
{
    if (string.IsNullOrEmpty(vvid))
    {
        return "Ryadok pustij abo null";
    }
    return char.ToUpper(vvid[0]) + vvid.Substring(1);
}

Console.WriteLine($"Onovlenij ryadok: {PershaLiteraZagolovna(VvidUsera())}");*/
