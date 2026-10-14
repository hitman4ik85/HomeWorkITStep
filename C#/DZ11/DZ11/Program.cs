//Task1
using System;

class GradeBook
{
    public delegate void AddGradeDelegate(int grade);
    public event AddGradeDelegate AddGrade;

    public void addGrade(int grade)
    {
        Console.WriteLine($"+ ocinka: {grade}");

        if (AddGrade != null)
        {
            AddGrade(grade);
        }
    }
}

class GradeListener
{
    public void gradeAdded(int grade)
    {
        Console.WriteLine($"User otrumav ocinky: {grade}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        GradeBook grade = new GradeBook();
        GradeListener user = new GradeListener();
        grade.AddGrade += user.gradeAdded;

        grade.addGrade(10);
        grade.addGrade(11);
        grade.addGrade(12);
    }
}