using System.ComponentModel.DataAnnotations;

namespace DZ3.Models
{
    public class Product
    {
        [Key]
        public int Id { get; set; }

        [Required]
        public string? ProductName { get; set; }

        [Required]
        public string? Manufacturer { get; set; }

        public int ProductCount { get; set; }

        [Required]
        public decimal Price { get; set; }
    }
}
