using System.Net;
using System.Net.Sockets;
using System.Text;

var broadcastAddress = IPAddress.Parse("235.5.5.11");
using var udpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

udpSocket.Bind(new IPEndPoint(IPAddress.Any, 8001));
udpSocket.SetSocketOption(SocketOptionLevel.IP, SocketOptionName.AddMembership, new MulticastOption(broadcastAddress));

Console.WriteLine("Multicast UDP Chat Client started. Listening for messages...");

byte[] data = new byte[256];

while (true)
{
    EndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);
    int bytesRead = udpSocket.ReceiveFrom(data, ref remoteEndPoint);
    string message = Encoding.UTF8.GetString(data, 0, bytesRead);

    Console.WriteLine($"[Message from {remoteEndPoint}]: {message}");
}