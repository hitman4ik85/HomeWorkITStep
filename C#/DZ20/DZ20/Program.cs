//Task1
using System;
using System.Linq;

class Program
{
    static void Main(String[] args)
    {
        string[] surname = { "Wilson", "Smith", "Johnson", "Williams", "Brown", "Taylor", "Orange" };

        var dovzhunaBilshe3s = surname.All(sur => sur.Length > 3);
        Console.WriteLine($"Vsi prizvusha majyt dovzhuny bilshe 3: {dovzhunaBilshe3s}");

        var chuVsiMajyt = surname.All(sur => sur.Length > 3 && sur.Length < 10);
        Console.WriteLine($"Vsi prizvusha majyt dovzhuny bilshe 3 i menshe 10: {chuVsiMajyt}");

        var pochatokIzW = surname.Any(sur => sur.StartsWith("W"));
        Console.WriteLine($"E prizvushe, scho pochinajetsja iz 'W': {pochatokIzW}");

        var chuZakinchNaY = surname.Any(sur => sur.EndsWith("Y"));
        Console.WriteLine($"E prizvushe, scho zakinchyetsja na 'Y': {chuZakinchNaY}");

        var chuIsnyeOrange = surname.Contains("Orange");
        Console.WriteLine($"Masuv prizvush mistut 'Orange': {chuIsnyeOrange}");

        var persheIzDovzh6 = surname.FirstOrDefault(sur => sur.Length == 6);
        Console.WriteLine($"Pershe prizvushe z dovzhunojy 6: {persheIzDovzh6}");

        var ostanneIzDovzhMenshe15 = surname.LastOrDefault(sur => sur.Length < 15);
        Console.WriteLine($"Ostanne prizvushe z dovzhunojy < 15: {ostanneIzDovzhMenshe15}");
    }
}



////Task2
//using System;
//using System.Collections.Generic;
//using System.Linq;

//class Zhyrnal
//{
//    public string Nazva { get; set; }
//    public string Zhanr { get; set; }
//    public int KilkistStorinok { get; set; }
//    public DateTime DataVidannya { get; set; }

//    public Zhyrnal(string nazva, string zhanr, int storіnku, DateTime data)
//    {
//        Nazva = nazva;
//        Zhanr = zhanr;
//        KilkistStorinok = storіnku;
//        DataVidannya = data;
//    }
//}

//class Program
//{
//    static void Main(String[] args)
//    {
//        List<Zhyrnal> zhyrnalu = new List<Zhyrnal>
//        {
//            new Zhyrnal("Polituchnui Zhyrnal", "Polituka", 50, new DateTime(2022, 5, 10)),
//            new Zhyrnal("Moda Zhyrnal", "Moda", 45, new DateTime(2023, 7, 15)),
//            new Zhyrnal("Sport Zhyrnal", "Sport", 35, new DateTime(2021, 9, 20)),
//            new Zhyrnal("Sad Ogorodnij Zhyrnal", "Sad ta gorod", 60, new DateTime(2023, 3, 18)),
//            new Zhyrnal("Avto Zhyrnal", "Avtomobili", 25, new DateTime(2022, 12, 5))
//        };

//        var vseBilsheZa30 = zhyrnalu.All(zh => zh.KilkistStorinok > 30);
//        Console.WriteLine($"Chu vsi zhyrnalu majyt kilkist storinok > 30: {vseBilsheZa30}");

//        var vsiPolModaSport = zhyrnalu.All(zh => zh.Zhanr == "Polіtika" || zh.Zhanr == "Moda" || zh.Zhanr == "Sport");
//        Console.WriteLine($"Chu vsi zhyrnalu zhanry «Polituka», «Moda» abo «Sport»: {vsiPolModaSport}");

//        var eSadTaGorod = zhyrnalu.Any(zh => zh.Zhanr == "Sad ta gorod");
//        Console.WriteLine($"Chu e zhyrnal y zhanrі «Sad ta gorod»: {eSadTaGorod}");

//        var eRubalka = zhyrnalu.Any(zh => zh.Zhanr == "Rubalka");
//        Console.WriteLine($"Chu e zhyrnal u zhanrі «Rubalka»: {eRubalka}");

//        var ePoljyvannja = zhyrnalu.Any(zh => zh.Zhanr.Equals("Poljyvannja", StringComparison.OrdinalIgnoreCase));
//        Console.WriteLine($"Chu e zhyrnalu pro «Poljyvannja»: {ePoljyvannja}");

//        var pershuj2022 = zhyrnalu.FirstOrDefault(zh => zh.DataVidannya.Year == 2022);
//        Console.WriteLine($"Pershuj zhyrnal 2022 roky: {pershuj2022?.Nazva}");

//        var ostannijAuto = zhyrnalu.LastOrDefault(zh => zh.Nazva.StartsWith("Avto"));
//        Console.WriteLine($"Ostannij zhyrnal, pochatok nazvu jakogo «Avto»: {ostannijAuto?.Nazva}");
//    }
//}