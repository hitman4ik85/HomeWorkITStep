using System.Net;
using System.Net.Sockets;
using System.Text;

var broadcastAddress = IPAddress.Parse("235.5.5.11");
using var udpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
var remoteEndPoint = new IPEndPoint(broadcastAddress, 8001);

Console.WriteLine("Multicast UDP Chat Server started. Enter messages to send.");

while (true)
{
    Console.Write("Enter message: ");
    string? message = Console.ReadLine();
    if (string.IsNullOrWhiteSpace(message)) continue;

    if (message.Equals("exit", StringComparison.OrdinalIgnoreCase)) break;

    byte[] data = Encoding.UTF8.GetBytes(message);
    udpSocket.SendTo(data, remoteEndPoint);
}

Console.WriteLine("Server terminated.");