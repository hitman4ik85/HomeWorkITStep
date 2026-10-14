
namespace DZ5.Models
{
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; } = null!;
        public double Balance { get; set; }

        public int LocationId { get; set; }
        public Location Location { get; set; } = null!;

        public List<GazStationTransaction> Transactions { get; set; } = new();
    }
}
