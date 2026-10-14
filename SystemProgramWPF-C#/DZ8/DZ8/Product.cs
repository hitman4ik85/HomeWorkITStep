using System.Globalization;
using System.Text.RegularExpressions;

namespace DZ8
{
    public class Product
    {
        public string Name { get; }
        public string Country { get; }
        public double Price { get; }

        public Product(string name, string country, double price)
        {
            Name = name;
            Country = country;
            Price = price;
        }

        public override string ToString()
        {
            // Формат: "Name (Country) - Price$"
            return $"{Name} ({Country}) - {Price.ToString("F2", CultureInfo.InvariantCulture)}$";
        }

        public static Product FromString(string productString)
        {
            try
            {
                // Регулярний вираз для нового формату "Name (Country) - Price$"
                var match = Regex.Match(productString, @"^(.*?)\s\((.*?)\)\s-\s(\d+([.,]\d{1,2})?)\$");

                if (!match.Success)
                {
                    throw new FormatException("Nekorektny format productu. Ochkuyetsya format: 'Name (Country) - Price$'.");
                }

                string name = match.Groups[1].Value.Trim();
                string country = match.Groups[2].Value.Trim();
                string priceText = match.Groups[3].Value.Trim();

                // Замінюємо кому на крапку перед парсингом
                priceText = priceText.Replace(',', '.');

                // Парсимо ціну
                double price = double.Parse(priceText, CultureInfo.InvariantCulture);

                return new Product(name, country, price);
            }
            catch (Exception ex)
            {
                throw new FormatException($"Pomylka parsu formatu: {ex.Message}");
            }
        }
    }
}
