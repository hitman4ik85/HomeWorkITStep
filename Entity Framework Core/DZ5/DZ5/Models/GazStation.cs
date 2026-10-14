namespace DZ5.Models
{
    public class GazStation
    {
        public int Id { get; set; }
        public string Name { get; set; } = null!;
        public int LocationId { get; set; }
        public Location Location { get; set; } = null!;
        public List<GazStationPoint> Points { get; set; } = new();
    }
}
