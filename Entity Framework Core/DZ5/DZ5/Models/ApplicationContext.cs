
using Microsoft.EntityFrameworkCore;

namespace DZ5.Models
{
    public class ApplicationContext : DbContext
    {
        public DbSet<User> Users { get; set; } = null!;
        public DbSet<Location> Locations { get; set; } = null!;
        public DbSet<GazStation> GazStations { get; set; } = null!;
        public DbSet<GazStationPoint> GazStationPoints { get; set; } = null!;
        public DbSet<GazStationTransaction> Transactions { get; set; } = null!;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlite("Data Source=gazstation.db");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>()
                .HasOne(u => u.Location)
                .WithMany()
                .HasForeignKey(u => u.LocationId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<GazStation>()
                .HasOne(gs => gs.Location)
                .WithMany()
                .HasForeignKey(gs => gs.LocationId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<GazStationPoint>()
                .HasOne(gsp => gsp.GazStation)
                .WithMany(gs => gs.Points)
                .HasForeignKey(gsp => gsp.GazStationId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<GazStationTransaction>()
                .HasOne(t => t.User)
                .WithMany(u => u.Transactions)
                .HasForeignKey(t => t.UserId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<GazStationTransaction>()
                .HasOne(t => t.GazStationPoint)
                .WithMany()
                .HasForeignKey(t => t.GazStationPointId)
                .OnDelete(DeleteBehavior.Cascade);
        }
    }
}
