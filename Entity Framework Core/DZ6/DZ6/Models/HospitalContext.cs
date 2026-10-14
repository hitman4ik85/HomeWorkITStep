using DZ6.Models;
using Microsoft.EntityFrameworkCore;

namespace DZ6.Models;

public class HospitalContext : DbContext
{
    public DbSet<Doctor> Doctors { get; set; }
    public DbSet<Pacient> Pacients { get; set; }
    public DbSet<Procedure> Procedures { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlite("Data Source=hospital.db");
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Doctor>()
            .HasMany(d => d.Pacients)
            .WithMany(p => p.Doctors);

        modelBuilder.Entity<Pacient>()
            .HasMany(p => p.Procedures)
            .WithMany(pr => pr.Pacients);
    }
}