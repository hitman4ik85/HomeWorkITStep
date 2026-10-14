

//Task1
using System;

namespace University
{
    namespace Faculty
    {
        public class Dekan
        {
            public string Name;

            public void Announce()
            {
                Console.WriteLine($"Vitae dekan: {Name}!");
            }
        }
    }

    namespace Department
    {
        public class Professor
        {
            public string Subject;

            public void Teach()
            {
                Console.WriteLine($"Professor prupodae predmet: {Subject}");
            }
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        University.Faculty.Dekan dekan = new University.Faculty.Dekan { Name = "Andrii Victorovich" };
        dekan.Announce();
        University.Department.Professor professor = new University.Department.Professor { Subject = "Informatuka" };
        professor.Teach();
    }
}



/*//Task2
using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Vvedit ocinky abo natusnit Enter: ");
        string vvid = Console.ReadLine();

        int? ocinka = null;

        if (!string.IsNullOrWhiteSpace(vvid))
        {
            try
            {
                ocinka = Convert.ToInt32(vvid);
            }
            catch
            {
                Console.WriteLine("Nevirnui vvid. Ocinka randomna.");
            }
        }

        int res = ocinka ?? new Random().Next(0, 101);

        Console.WriteLine("Ocinka: " + res);
    }
}*/