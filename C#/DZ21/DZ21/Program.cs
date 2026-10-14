using System;
using System.Xml;

class Program
{
    static void Main(string[] args)
    {
        XmlTextWriter writer = null;  // Створюєм XML-файл зі списком замовлень і товарів

        try
        {
            writer = new XmlTextWriter("Orders.xml", System.Text.Encoding.Unicode);
            writer.Formatting = Formatting.Indented;

            writer.WriteStartDocument();
            writer.WriteStartElement("Orders");

            writer.WriteStartElement("Order");
            writer.WriteAttributeString("id", "1");

            writer.WriteStartElement("Product");
            writer.WriteElementString("Name", "Laptop");
            writer.WriteElementString("Kilkist", "2");
            writer.WriteElementString("Price", "1200");
            writer.WriteEndElement(); // Закриваємо Product

            writer.WriteStartElement("Product");
            writer.WriteElementString("Name", "Mouse");
            writer.WriteElementString("Kilkist", "5");
            writer.WriteElementString("Price", "25");
            writer.WriteEndElement(); // Закриваємо Product

            writer.WriteEndElement(); // Закриваємо Order

            writer.WriteStartElement("Order");
            writer.WriteAttributeString("id", "2");

            writer.WriteStartElement("Product");
            writer.WriteElementString("Name", "Keyboard");
            writer.WriteElementString("Kilkist", "3");
            writer.WriteElementString("Price", "50");
            writer.WriteEndElement(); // Закриваємо Product

            writer.WriteStartElement("Product");
            writer.WriteElementString("Name", "Monitor");
            writer.WriteElementString("Kilkist", "1");
            writer.WriteElementString("Price", "300");
            writer.WriteEndElement(); // Закриваємо Product

            writer.WriteEndElement(); // Закриваємо Order
            writer.WriteEndElement(); // Закриваємо Orders

            writer.WriteEndDocument();
            Console.WriteLine("XML файл Orders.xml створено");
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
        finally
        {
            if (writer != null)
                writer.Close();
        }

        XmlDocument doc = new XmlDocument();
        doc.Load("Orders.xml");

        XmlNodeList orderNodes = doc.SelectNodes("/Orders/Order");
        Console.WriteLine("\nDokyment Orders.xml:");

        foreach (XmlNode ordNode in orderNodes)
        {
            Console.WriteLine($"Zakaz ID: {ordNode.Attributes["id"].Value}");

            XmlNodeList productNodes = ordNode.SelectNodes("Product");
            foreach (XmlNode prodNode in productNodes)
            {
                Console.WriteLine($"  Tovar: {prodNode["Name"].InnerText}");
                Console.WriteLine($"  Vsjogo: {prodNode["Kilkist"].InnerText}");
                Console.WriteLine($"  Cina: {prodNode["Price"].InnerText}");
                Console.WriteLine();
            }
        }
    }
}












//using System;
//using System.Xml;

//class Program
//{
//    static void Main(string[] args)
//    {
//        XmlTextWriter writer = null;  // Створюєм XML-файл зі списком замовлень і товарів
//        try
//        {
//            writer = new XmlTextWriter("Orders.xml", System.Text.Encoding.Unicode);
//            writer.Formatting = Formatting.Indented;

//            writer.WriteStartDocument();
//            writer.WriteStartElement("Orders");

//            writer.WriteStartElement("Order");
//            writer.WriteAttributeString("id", "1");

//            writer.WriteStartElement("Product");
//            writer.WriteElementString("Name", "Laptop");
//            writer.WriteElementString("Kilkist", "2");
//            writer.WriteElementString("Price", "1200");
//            writer.WriteEndElement(); // Закриваємо Product

//            writer.WriteStartElement("Product");
//            writer.WriteElementString("Name", "Mouse");
//            writer.WriteElementString("Kilkist", "5");
//            writer.WriteElementString("Price", "25");
//            writer.WriteEndElement(); // Закриваємо Product

//            writer.WriteEndElement(); // Закриваємо Order

//            writer.WriteStartElement("Order");
//            writer.WriteAttributeString("id", "2");

//            writer.WriteStartElement("Product");
//            writer.WriteElementString("Name", "Keyboard");
//            writer.WriteElementString("Kilkist", "3");
//            writer.WriteElementString("Price", "50");
//            writer.WriteEndElement(); // Закриваємо Product

//            writer.WriteStartElement("Product");
//            writer.WriteElementString("Name", "Monitor");
//            writer.WriteElementString("Kilkist", "1");
//            writer.WriteElementString("Price", "300");
//            writer.WriteEndElement(); // Закриваємо Product

//            writer.WriteEndElement(); // Закриваємо Order
//            writer.WriteEndElement(); // Закриваємо Orders

//            writer.WriteEndDocument();
//            Console.WriteLine("XML файл Orders.xml створено");
//        }
//        catch (Exception ex)
//        {
//            Console.WriteLine(ex.Message);
//        }
//        finally
//        {
//            if (writer != null)
//                writer.Close();
//        }

//        XmlTextReader reader = new XmlTextReader("Orders.xml");
//        Console.WriteLine("\nDokyment Orders.xml (z XmlTextReader):");

//        while (reader.Read())
//        {
//            if (reader.NodeType == XmlNodeType.Element)
//            {
//                if (reader.Name == "Order" && reader.HasAttributes)
//                {
//                    Console.WriteLine($"Zakaz ID: {reader.GetAttribute("id")}");
//                }
//                else if (reader.Name == "Product")
//                {
//                    Console.WriteLine("  Tovar:");
//                }
//                else if (reader.Name == "Name")
//                {
//                    reader.Read();
//                    Console.WriteLine($"    Nazva: {reader.Value}");
//                }
//                else if (reader.Name == "Kilkist")
//                {
//                    reader.Read();
//                    Console.WriteLine($"    Vsjogo: {reader.Value}");
//                }
//                else if (reader.Name == "Price")
//                {
//                    reader.Read();
//                    Console.WriteLine($"    Cina: {reader.Value}");
//                }
//            }
//        }

//        reader.Close();
//    }
//}