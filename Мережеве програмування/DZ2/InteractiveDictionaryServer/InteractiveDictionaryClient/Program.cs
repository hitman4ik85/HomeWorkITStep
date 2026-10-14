using System.Net.Sockets;
using System.Text;

using TcpClient tcpClient = new TcpClient();
await tcpClient.ConnectAsync("127.0.0.1", 8888);
var stream = tcpClient.GetStream();

Console.WriteLine("Enter word for translation or 'END' to exit:");
while (true)
{
    string word = Console.ReadLine();
    if (string.IsNullOrEmpty(word)) continue;

    if (word == "END")
    {
        await stream.WriteAsync(Encoding.UTF8.GetBytes("END\n"));
        break;
    }

    byte[] data = Encoding.UTF8.GetBytes(word + '\n');
    await stream.WriteAsync(data);

    var response = new List<byte>();
    int bytesRead;
    while ((bytesRead = stream.ReadByte()) != '\n')
    {
        response.Add((byte)bytesRead);
    }

    var translation = Encoding.UTF8.GetString(response.ToArray());
    Console.WriteLine($"Translation: {translation}");
}
Console.WriteLine("Session ended");