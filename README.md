using System;

class Staff
{
    public string Name { get; set; }
    public string Department { get; set; }
    public double BaseSalary { get; set; }

    public Staff(string name, string department, double baseSalary)
    {
        Name = name;
        Department = department;
        BaseSalary = baseSalary;
    }

    public virtual double CalculateSalary()
    {
        return BaseSalary;
    }
}

class Lecturer : Staff
{
    public Lecturer(string name, string department, double baseSalary)
        : base(name, department, baseSalary) { }

    public override double CalculateSalary()
    {
        return BaseSalary + (BaseSalary * 0.2);
    }
}

class Administrator : Staff
{
    public Administrator(string name, string department, double baseSalary)
        : base(name, department, baseSalary) { }

    public override double CalculateSalary()
    {
        return BaseSalary + 300;
    }
}

class Program
{
    static void PrintStaff(Staff s)
    {
        Console.WriteLine($"{s.Name} ({s.Department}) => Total Salary: {s.CalculateSalary()}");
    }

    static void Main()
    {
        Staff s1 = new Lecturer("Lina", "CS", 1000);
        Staff s2 = new Lecturer("Omar", "SE", 1200);
        Staff s3 = new Administrator("Ahmad", "IT", 900);
        Staff s4 = new Administrator("Sara", "HR", 950);

        PrintStaff(s1);
        PrintStaff(s2);
        PrintStaff(s3);
        PrintStaff(s4);
    }
}
