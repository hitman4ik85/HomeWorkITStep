
using DZ5.Models;

namespace DZ5
{
    public static class DatabaseInitializer
    {
        public static void Initialize(ApplicationContext db)
        {
            db.Database.EnsureDeleted();
            db.Database.EnsureCreated();

            Location symu = new Location { City = "Суми", Address = "Сумська, 12" };
            Location harkiv = new Location { City = "Харкiв", Address = "Харкiвська, 45" };
            db.Locations.AddRange(symu, harkiv);

            GazStation station1 = new GazStation { Name = "Сумська СТ", Location = symu };
            GazStation station2 = new GazStation { Name = "Харкiвська СТ", Location = harkiv };
            db.GazStations.AddRange(station1, station2);

            GazStationPoint point1 = new GazStationPoint
            {
                GazStation = station1,
                MaxCapacity = 5000,
                CurrentFuel = 3000,
                PricePerLiter = 50
            };
            GazStationPoint point2 = new GazStationPoint
            {
                GazStation = station2,
                MaxCapacity = 7000,
                CurrentFuel = 5000,
                PricePerLiter = 55
            };
            db.GazStationPoints.AddRange(point1, point2);

            User user1 = new User { Name = "Андрiй", Balance = 5000, Location = symu };
            User user2 = new User { Name = "Алiса", Balance = 2500, Location = harkiv };
            User user3 = new User { Name = "Михайло", Balance = 3000, Location = symu };
            User user4 = new User { Name = "Олена", Balance = 4000, Location = harkiv };
            User user5 = new User { Name = "Денис", Balance = 3500, Location = symu };

            db.Users.AddRange(user1, user2, user3, user4, user5);

            db.SaveChanges();
        }
    }
}
