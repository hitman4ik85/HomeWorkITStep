//Task1
using System;

public interface IOutput
{
    void show();
    void show(string info);
}
public class Array : IOutput
{
    private int[] arr;
    public Array(int size)
    {
        this.arr = new int[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand.Next(1, 101);
        }
    }
    public void show()
    {
        Console.WriteLine("Masuv:");
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i] + " ");
        }
        Console.WriteLine();
    }
    public void show(string info)
    {
        Console.WriteLine("Z Info: " + info);
        show();
    }
}

class Program
{
    public static void Main(string[] args)
    {
        Array myArr = new Array(5);
        myArr.show();
        Console.WriteLine();
        myArr.show("Ce nash masuv");
    }
}
