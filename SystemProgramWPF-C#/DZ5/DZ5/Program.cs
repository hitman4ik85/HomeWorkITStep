using System;

namespace DZ5
{
    public class Program
    {
        public class Book
        {
            public string title;
            public string author;
            public int year;

            public Book(string title, string author, int year)
            {
                this.title = title;
                this.author = author;
                this.year = year;
            }
        }

        static unsafe void Main(string[] args)
        {
            Book[] books = new Book[]
            {
                new Book("Book1", "Author1", 2000),
                new Book("Book2", "Author2", 2005),
                new Book("Book3", "Author3", 2010),
                new Book("Book4", "Author4", 2015),
                new Book("Book5", "Author5", 2020)
            };

            fixed (Book* p = &books[0])
            {
                Console.WriteLine("Before change:");
                for (int i = 0; i < books.Length; i++)
                {
                    Console.WriteLine($"Book {i + 1}: Title: {(p + i)->title}, Author: {(p + i)->author}, Year: {(p + i)->year}, Address: {(long)(p + i)}");
                }

                for (int i = 0; i < books.Length; i++)
                {
                    (p + i)->title = $"NewTitle{i + 1}";
                    (p + i)->year += 5;
                }

                Console.WriteLine("\nAfter change:");
                for (int i = 0; i < books.Length; i++)
                {
                    Console.WriteLine($"Book {i + 1}: Title: {(p + i)->title}, Author: {(p + i)->author}, Year: {(p + i)->year}, Address: {(long)(p + i)}");
                }
            }
        }
    }
}


