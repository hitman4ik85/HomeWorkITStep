//Task1
using Microsoft.VisualBasic;
using System;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics;
using System.Reflection;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
public class AvtorInfoAttribute : Attribute
{
    string firstName;
    string lastName;
    DateTime date = DateTime.Now;

    public AvtorInfoAttribute(string firstName, string lastName)
    {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public override string ToString()
    {
        return $"Avtor: {firstName} {lastName}, Date: {date}";
    }
}

[AvtorInfo("Andrii", "Uroichenko")]
public class UserTest
{
    public int id { get; set; }
    public string firstName { get; set; }
    public string lastName { get; set; }
    public string address { get; set; }

    [Obsolete("This method is old. Use showNewInfo.")]
    public void showOldInfo()
    {
        Console.WriteLine($"Old User Info: {id}, {address}, {firstName} {lastName}");
    }

    public void showNewInfo()
    {
        Console.WriteLine($"New User Info: {id}, {firstName} {lastName}, {address}");
    }
}

class Program
{
    public static void Main(String[] args)
    {
        Console.WriteLine("Attributes of class UserTest:");
        foreach (var attr in typeof(UserTest).GetCustomAttributes())
        {
            Console.WriteLine(attr);
        }

        UserTest user = new UserTest
        {
            id = 1,
            firstName = "Taras",
            lastName = "Buhra",
            address = "st. Kirova 3/2"
        };

        ObsoleteAttribute attribute = (ObsoleteAttribute)Attribute.GetCustomAttribute(typeof(UserTest).GetMethod("showOldInfo"), typeof(ObsoleteAttribute));
        Console.WriteLine(attribute.Message);
        user.showOldInfo();

        Console.WriteLine("showNewInfo: ");
        user.showNewInfo();
    }
}