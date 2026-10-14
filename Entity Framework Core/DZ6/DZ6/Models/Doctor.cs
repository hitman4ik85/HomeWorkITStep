using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ6.Models;

public class Doctor
{
    public int Id { get; set; }
    public string? Name { get; set; }
    public string? Surname { get; set; }
    public List<Pacient> Pacients { get; set; } = new();
}
