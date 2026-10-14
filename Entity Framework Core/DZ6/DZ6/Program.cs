using DZ6.Models;
using Microsoft.EntityFrameworkCore;
namespace DZ6;

class Program
{
    static void Main(string[] args)
    {
        using (HospitalContext db = new HospitalContext())
        {
            db.Database.EnsureDeleted();
            db.Database.EnsureCreated();

            // Ініціалізація даних
            Doctor doctor1 = new Doctor { Name = "Thomas", Surname = "Gerada" };
            Doctor doctor2 = new Doctor { Name = "Emily", Surname = "Smith" };
            db.Doctors.AddRange(doctor1, doctor2);

            Pacient pacient1 = new Pacient { Name = "John Doe" };
            Pacient pacient2 = new Pacient { Name = "Jane Roe" };
            db.Pacients.AddRange(pacient1, pacient2);

            Procedure procedure1 = new Procedure { Name = "Cardiac Exam" };
            Procedure procedure2 = new Procedure { Name = "Neurological Exam" };
            db.Procedures.AddRange(procedure1, procedure2);

            // Встановлення зв’язків
            doctor1.Pacients.Add(pacient1);
            doctor2.Pacients.Add(pacient2);

            pacient1.Procedures.Add(procedure1);
            pacient2.Procedures.Add(procedure2);

            db.SaveChanges();
            Console.WriteLine("Данi успiшно iнiцiалiзованi.");
        }

        using (HospitalContext db = new HospitalContext())
        {
            // Виведення лікарів та їх пацієнтів
            var doctors = db.Doctors.Include(d => d.Pacients).ToList();
            Console.WriteLine("Лiкарi та їх пацiєнти:");
            foreach (var doctor in doctors)
            {
                Console.WriteLine($"Лiкар: {doctor.Name} {doctor.Surname}");
                foreach (var pacient in doctor.Pacients)
                {
                    Console.WriteLine($"  Пацiєнт: {pacient.Name}");
                }
            }

            // Виведення пацієнтів та їх процедур
            var pacients = db.Pacients.Include(p => p.Procedures).ToList();
            Console.WriteLine("\nПацiєнти та їх процедури:");
            foreach (var pacient in pacients)
            {
                Console.WriteLine($"Пацiєнт: {pacient.Name}");
                foreach (var procedure in pacient.Procedures)
                {
                    Console.WriteLine($"  Процедура: {procedure.Name}");
                }
            }
        }
    }
}