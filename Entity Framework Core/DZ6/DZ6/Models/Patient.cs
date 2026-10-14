using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ6.Models;

public class Pacient
{
    public int Id { get; set; }
    public string? Name { get; set; }
    public List<Doctor> Doctors { get; set; } = new();
    public List<Procedure> Procedures { get; set; } = new();
}
