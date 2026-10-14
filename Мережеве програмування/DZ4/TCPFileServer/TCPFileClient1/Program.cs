using System.Net.Sockets;
using System.IO;

using TcpClient client = new TcpClient();
await client.ConnectAsync("127.0.0.1", 8888);
var stream = client.GetStream();

string savePath = "downloaded.jpg";
using FileStream fileStream = new FileStream(savePath, FileMode.Create, FileAccess.Write);

byte[] buffer = new byte[20000]; // 20 KB
int bytesRead;
long totalBytesRead = 0;
const int progressBarWidth = 50;

// Читаємо розмір файлу (перші 8 байт передає сервер)
byte[] fileSizeBuffer = new byte[8];
await stream.ReadAsync(fileSizeBuffer, 0, fileSizeBuffer.Length);
long fileSize = BitConverter.ToInt64(fileSizeBuffer, 0);
Console.WriteLine($"Downloading file... Size: {fileSize} bytes");

// Завантаження файлу з відображенням прогрес-бару
while ((bytesRead = await stream.ReadAsync(buffer, 0, buffer.Length)) > 0)
{
    await fileStream.WriteAsync(buffer, 0, bytesRead);
    totalBytesRead += bytesRead;
    
    // відображення прогрес-бару
    double progress = (double)totalBytesRead / fileSize;
    int filledBars = (int)(progress * progressBarWidth);
    Console.Write($"\r[{new string('#', filledBars)}{new string('-', progressBarWidth - filledBars)}] {progress * 100:F2}%");
}

Console.WriteLine("\nDownload complete.");
client.Close();