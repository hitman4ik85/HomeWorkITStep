using System.Net;
using System.Net.Sockets;

namespace TcpChat.Models;

public class ServerObject
{
    private TcpListener _tcpListener = new TcpListener(IPAddress.Any, 8888);
    private List<ClientObject> clients = new List<ClientObject>();

    protected internal void RemoveConnection(string id)
    {
        ClientObject? client = clients.FirstOrDefault(c => c.Id == id);
        if (client != null) clients.Remove(client);
        client?.Close();
    }

    protected internal async Task ListenAsync()
    {
        try
        {
            _tcpListener.Start();
            Console.WriteLine("server starting. w8 connection...");
            while (true)
            {
                TcpClient tcpClient = await _tcpListener.AcceptTcpClientAsync();

                ClientObject clientObject = new ClientObject(tcpClient, this);
                clients.Add(clientObject);

                Task.Run(clientObject.ProcessAsync);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }
        finally
        {
            Disconect();
        }
    }

    protected internal async Task BroadcastMessageAsync(string message, string id)
    {
        foreach (var client in clients)
        {
            if (client.Id != id)
            {
                await client.Writer.WriteLineAsync(message);
                await client.Writer.FlushAsync();
            }
        }
    }

    protected internal void Disconect()
    {
        foreach (var client in clients)
        {
            client.Close();
        }
        _tcpListener.Stop();
    }
    
}