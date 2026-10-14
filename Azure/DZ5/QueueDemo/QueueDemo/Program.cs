using Azure.Storage.Queues;
using Azure.Storage.Queues.Models;
using Microsoft.Extensions.Configuration;
using System.Text.Json;
using System.Threading.Tasks;
using QueueDemo.Models;

namespace QueueDemo
{
    public class Program
    {
        static QueueClient queueClient;
        static async Task Main(string[] args)
        {
            var configuration = new ConfigurationBuilder().AddJsonFile("config.json").Build();
            var queueName = configuration["QueueName"];
            var connectionString = configuration["AzureConnString"];

            queueClient = new QueueClient(connectionString, queueName);
            await queueClient.CreateIfNotExistsAsync();

            string msg1 = "This is the first message!";
            string msg2 = "This is the second message!";
            string msg3 = "This is the thrid message!";

            Book b1 = new Book("Azure", "Lane Osmon", 2025);
            await AddBookMessage(b1);
            await GetBookMessages();

            //await AddStringMessage(msg1);
            //await AddStringMessage(msg2);
            //await AddStringMessage(msg3);

            //await GetStringMessages();
            //await PeekStringMessages(3);
        }

        private static async Task AddBookMessage(Book book)
        {
            try
            {
                string json = JsonSerializer.Serialize(book);
                await queueClient.SendMessageAsync(
                    json,
                    TimeSpan.FromSeconds(10),
                    TimeSpan.FromMinutes(120)
                    );
                Console.WriteLine($"Book '{book.Title}' added to the queue.");
                QueueProperties properties = queueClient.GetProperties();
                Console.WriteLine("Number of messages: " + properties.ApproximateMessagesCount);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"AddBookMessage: " + ex.Message);
            }
        }

        private static async Task GetBookMessages(int number = 1, bool toDelete = false)
        {
            try
            {
                QueueMessage[] messages = await queueClient.ReceiveMessagesAsync(number);
                foreach (QueueMessage message in messages)
                {
                    string json = message.Body.ToString();
                    Book book = JsonSerializer.Deserialize<Book>(json);
                    Console.WriteLine($"Book: {book.Title}, Author: {book.Author}, Year: {book.Year}");
                    if (toDelete)
                    {
                        await queueClient.DeleteMessageAsync(message.MessageId, message.PopReceipt);
                        Console.WriteLine("Message deleted.");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"GetBookMessages: " + ex.Message);
            }
        }

        private static async Task PeekStringMessages(int number = 1)
        {
            try
            {
                PeekedMessage[] messages = await queueClient.PeekMessagesAsync(number);
                foreach (PeekedMessage message in messages)
                {
                    Console.WriteLine($"Message: {message.Body}");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"PeekStringMessages: " + ex.Message);
            }
        }

        private static async Task GetStringMessages(int number = 1, bool toDelete = false)
        {
            try
            {
                QueueMessage[] messages = await queueClient.ReceiveMessagesAsync(number);
                foreach (QueueMessage message in messages)
                {
                    Console.WriteLine($"Message: {message.Body}");
                    if (toDelete)
                    {
                        await queueClient.DeleteMessageAsync(message.MessageId, message.PopReceipt);
                        Console.WriteLine("Message deleted.");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"GetStringMessages: " + ex.Message);
            }
        }

        private static async Task AddStringMessage(string msg)
        {
            try
            {
                await queueClient.SendMessageAsync(
                    msg,
                    TimeSpan.FromSeconds(10), // Visibility timeout
                    TimeSpan.FromMinutes(120) // Time to live
                    );
                Console.WriteLine($"Message '{msg}' added to the queue.");
                QueueProperties properties = queueClient.GetProperties();
                Console.WriteLine("Number of messages: " + properties.ApproximateMessagesCount);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"AddStringMessage: " + ex.Message);
            }
        }
    }
}