using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ5.Models
{
    public class Location
    {
        public int Id { get; set; }
        public string City { get; set; } = null!;
        public string Address { get; set; } = null!;
    }
}
