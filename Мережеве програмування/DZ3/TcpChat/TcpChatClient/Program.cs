using System.Net.Sockets;
using System.IO;

class Program
{
    private static StreamWriter? writer;
    private static StreamReader? reader;

    static async Task Main(string[] args)
    {
        Console.Write("Enter server IP (default 127.0.0.1): ");
        string serverIp = Console.ReadLine();
        if (string.IsNullOrWhiteSpace(serverIp)) serverIp = "127.0.0.1";

        Console.Write("Enter your name: ");
        string userName = Console.ReadLine() ?? "Anonymous";

        await ConnectToServerAsync(serverIp, userName);
    }

    private static async Task ConnectToServerAsync(string serverIp, string userName)
    {
        try
        {
            using TcpClient tcpClient = new TcpClient();
            await tcpClient.ConnectAsync(serverIp, 8888);

            var stream = tcpClient.GetStream();
            writer = new StreamWriter(stream);
            reader = new StreamReader(stream);

            // Відправляємо ім'я користувача серверу
            await writer.WriteLineAsync(userName);
            await writer.FlushAsync();

            // Запускаємо читання в окремому потоці
            Task.Run(ReadMessagesAsync);

            Console.WriteLine("Connected to chat. Enter your messages:");
            while (true)
            {
                string message = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(message)) continue;

                await writer.WriteLineAsync(message);
                await writer.FlushAsync();

                if (message.Equals("exit", StringComparison.OrdinalIgnoreCase)) break;
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
        finally
        {
            writer?.Close();
            reader?.Close();
            Console.WriteLine("Disconnected from server.");
        }
    }

    private static async Task ReadMessagesAsync()
    {
        try
        {
            while (true)
            {
                string? message = await reader?.ReadLineAsync();
                if (!string.IsNullOrEmpty(message))
                {
                    Console.WriteLine(message);
                }
            }
        }
        catch (Exception)
        {
            Console.WriteLine("Connection closed.");
        }
    }
}