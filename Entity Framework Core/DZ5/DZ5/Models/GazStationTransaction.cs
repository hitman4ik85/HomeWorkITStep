
namespace DZ5.Models
{
    public class GazStationTransaction
    {
        public int Id { get; set; }
        public int UserId { get; set; }
        public User User { get; set; } = null!;

        public int GazStationPointId { get; set; }
        public GazStationPoint GazStationPoint { get; set; } = null!;

        public double Amount { get; set; }
        public double TotalCost { get; set; }
        public DateTime Date { get; set; } = DateTime.Now;
    }
}
