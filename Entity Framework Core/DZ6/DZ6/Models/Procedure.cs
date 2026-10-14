
namespace DZ6.Models;

public class Procedure
{
    public int Id { get; set; }
    public string? Name { get; set; }
    public List<Pacient> Pacients { get; set; } = new();
}
