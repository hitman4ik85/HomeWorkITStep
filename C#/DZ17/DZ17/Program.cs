//Task1
using System;
using System.IO;

class Program
{
    static void ShowFile(string directoryPath)
    {
        DirectoryInfo dirInfo = new DirectoryInfo(directoryPath);

        if (dirInfo.Exists)
        {
            FileInfo[] files = dirInfo.GetFiles();

            if (files.Length > 0)
            {
                foreach (FileInfo file in files)
                {
                    Console.WriteLine($"\nVmist faily: {file.Name}");
                    using (StreamReader sr = file.OpenText())
                    {
                        Console.WriteLine(sr.ReadToEnd());
                    }
                }
            }
            else
            {
                Console.WriteLine("Y durectorii nemae failiv.");
            }
        }
        else
        {
            Console.WriteLine("Durectorija ne znajdena.");
        }
    }

    static void Main(string[] args)
    {
        Console.Write("Vvedit shljah do durectorii: ");
        string directoryPath = Console.ReadLine();

        ShowFile(directoryPath);
    }
}



////Task1-1 tilku z txt
//using System;
//using System.IO;

//class Program
//{
//    static void ShowTextFile(string directoryPath)
//    {
//        DirectoryInfo dirInfo = new DirectoryInfo(directoryPath);

//        if (dirInfo.Exists)
//        {
//            FileInfo[] files = dirInfo.GetFiles("*.txt");

//            if (files.Length > 0)
//            {
//                foreach (FileInfo file in files)
//                {
//                    Console.WriteLine($"\nVmist faily: {file.Name}");
//                    using (StreamReader sr = file.OpenText())
//                    {
//                        Console.WriteLine(sr.ReadToEnd());
//                    }
//                }
//            }
//            else
//            {
//                Console.WriteLine("Y durectorii nemae failiv txt.");
//            }
//        }
//        else
//        {
//            Console.WriteLine("Durectorija ne znajdena.");
//        }
//    }

//    static void Main(string[] args)
//    {
//        Console.Write("Vvedit shljah do durectorii: ");
//        string directoryPath = Console.ReadLine();

//        ShowTextFile(directoryPath);
//    }
//}