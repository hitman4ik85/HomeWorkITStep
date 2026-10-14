using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ5.Models
{
    public class GazStationPoint
    {
        public int Id { get; set; }
        public int GazStationId { get; set; }
        public GazStation GazStation { get; set; } = null!;
        public double MaxCapacity { get; set; }
        public double CurrentFuel { get; set; }
        public double PricePerLiter { get; set; }
    }
}