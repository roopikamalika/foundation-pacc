import java.util.Scanner;

class Student
{
    String name;
    int rollno;
    Scanner sc = new Scanner(System.in);

    void getDetails()
    {
        System.out.print("Enter Name: ");
        name = sc.next();

        System.out.print("Enter Roll No: ");
        rollno = sc.nextInt();
    }

    void displayDetails()
    {
        System.out.println("Name : " + name);
        System.out.println("Roll No : " + rollno);
    }
}

class Marks extends Student
{
    int m1, m2, m3, sum;
    double avg;

    void getMarks()
    {
        System.out.print("Enter Mark 1: ");
        m1 = sc.nextInt();

        System.out.print("Enter Mark 2: ");
        m2 = sc.nextInt();

        System.out.print("Enter Mark 3: ");
        m3 = sc.nextInt();
    }

    void calculate()
    {
        sum = m1 + m2 + m3;
        avg = sum / 3.0;
    }

    void displayResult()
    {
        displayDetails();
        System.out.println("Sum = " + sum);
        System.out.println("Average = " + avg);
    }
}

public class Inheritance
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        Marks s[] = new Marks[n];

        for(int i = 0; i < n; i++)
        {
            s[i] = new Marks();

            System.out.println("\nStudent " + (i + 1));

            s[i].getDetails();
            s[i].getMarks();
            s[i].calculate();
        }

        System.out.println("\n----- Student Details -----");

        for(int i = 0; i < n; i++)
        {
            System.out.println("\nStudent " + (i + 1));
            s[i].displayResult();
        }
    }
}