using System.Net;
using System.Net.Sockets;

TcpListener server = new TcpListener(IPAddress.Any, 8888);
server.Start();
Console.WriteLine("Server started....");

while (true)
{
    TcpClient client = server.AcceptTcpClient();
    Thread thread = new Thread(() => HandleClient(client));
    thread.Start();
}

void HandleClient(TcpClient client)
{
    NetworkStream stream = client.GetStream();
    string filePath = "D:\\IT Step Shag\\!!!!!!!PK Kurs!!!!!!!!\\Мережеве програмування\\Lesson3\\TCPFileServer\\TCPFileServer\\Screenshot_1.jpg";
    byte[] buffer = new byte[20000]; //20 KB
    using (FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read))
    {
        int bytesRead;
        while ((bytesRead = fileStream.Read(buffer,0,buffer.Length)) > 0)
        {
            stream.Write(buffer,0,bytesRead);
            Console.WriteLine($"Transfer {bytesRead} bytes...");
            Thread.Sleep(1000);
        }
    }
    client.Close();
}