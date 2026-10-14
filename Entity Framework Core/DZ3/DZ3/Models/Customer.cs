using System.ComponentModel.DataAnnotations;

namespace DZ3.Models
{
    public class Customer
    {
        [Key]
        public int Id { get; set; }

        [Required]
        public string? FirstName { get; set; }
    }
}
