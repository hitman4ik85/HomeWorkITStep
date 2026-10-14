using System;
using System.IO;
using System.Net.NetworkInformation;

namespace NetworkScanner
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Program start work");

            // Отримуємо всі мережеві інтерфейси
            var adapters = NetworkInterface.GetAllNetworkInterfaces();
            Console.WriteLine($"Find {adapters.Length} devices");

            // Відкриваємо файл для запису
            using (var writer = new StreamWriter("network_info.txt"))
            {
                foreach (var adapter in adapters)
                {
                    Console.WriteLine("==========================================");
                    Console.WriteLine($"Id device: {adapter.Id}");
                    Console.WriteLine($"Name device: {adapter.Name}");
                    Console.WriteLine($"Description device: {adapter.Description}");
                    Console.WriteLine($"NetInterfaceType: {adapter.NetworkInterfaceType}");
                    Console.WriteLine($"PhysicalAddress: {adapter.GetPhysicalAddress()}");
                    Console.WriteLine($"Status: {adapter.OperationalStatus}");
                    Console.WriteLine($"Speed: {adapter.Speed}");

                    writer.WriteLine("==========================================");
                    writer.WriteLine($"Id device: {adapter.Id}");
                    writer.WriteLine($"Name device: {adapter.Name}");
                    writer.WriteLine($"Description device: {adapter.Description}");
                    writer.WriteLine($"NetInterfaceType: {adapter.NetworkInterfaceType}");
                    writer.WriteLine($"PhysicalAddress: {adapter.GetPhysicalAddress()}");
                    writer.WriteLine($"Status: {adapter.OperationalStatus}");
                    writer.WriteLine($"Speed: {adapter.Speed}");
                }

                var ipProps = IPGlobalProperties.GetIPGlobalProperties();
                var connections = ipProps.GetActiveTcpConnections();
                Console.WriteLine($"All {connections.Length} active connections");
                writer.WriteLine($"All {connections.Length} active connections");

                foreach (var connection in connections)
                {
                    Console.WriteLine("=================");
                    Console.WriteLine($"Local address: {connection.LocalEndPoint.Address}:{connection.LocalEndPoint.Port}");
                    Console.WriteLine($"Remote address: {connection.RemoteEndPoint.Address}:{connection.RemoteEndPoint.Port}");
                    Console.WriteLine($"State: {connection.State}");

                    writer.WriteLine("=================");
                    writer.WriteLine($"Local address: {connection.LocalEndPoint.Address}:{connection.LocalEndPoint.Port}");
                    writer.WriteLine($"Remote address: {connection.RemoteEndPoint.Address}:{connection.RemoteEndPoint.Port}");
                    writer.WriteLine($"State: {connection.State}");
                }
            }

            Console.WriteLine("Network information saved to 'network_info.txt'.");
            Console.WriteLine("Program end work");
        }
    }
}
