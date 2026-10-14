using System.Net;
using System.Net.Sockets;
using System.Text;

var tcpListener = new TcpListener(IPAddress.Any, 8888);
var words = new Dictionary<string, string>()
{
    {"red", "червоний"},
    {"blue", "синій"},
    {"green", "зелений"}
};

try
{
    tcpListener.Start();
    Console.WriteLine("Server started... wait connection...");

    using var tcpClient = tcpListener.AcceptTcpClient();
    var stream = tcpClient.GetStream();
    var response = new List<byte>();
    int bytesRead;

    while (true)
    {
        while ((bytesRead = stream.ReadByte()) != '\n')
        {
            response.Add((byte)bytesRead);
        }

        var word = Encoding.UTF8.GetString(response.ToArray());
        if (word == "END") break;

        Console.WriteLine($"Ended translate word {word}");
        if (!words.TryGetValue(word, out var translation)) translation = "word miss in dictionary";
        translation += '\n';
        await stream.WriteAsync(Encoding.UTF8.GetBytes(translation));
        response.Clear();
    }
}
finally
{
    tcpListener.Stop();
}
