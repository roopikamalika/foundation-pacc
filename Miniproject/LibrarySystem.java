import java.util.Scanner;

abstract class Library
{
    String[] bookName = new String[10];
    int[] quantity = new int[10];
    int n;

    abstract void addBooks();
    abstract void issueBook(String book);
    abstract void returnBook(String book);
    abstract void searchBook(String book);
    abstract void displayBooks();
}

class LibrarySystem extends Library
{
    Scanner sc = new Scanner(System.in);

    void addBooks()
    {
        System.out.print("Enter Number of Books: ");
        n = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter Book Name: ");
            bookName[i] = sc.nextLine();

            System.out.print("Enter Quantity: ");
            quantity[i] = sc.nextInt();
            sc.nextLine();
        }
    }

    void issueBook(String book)
    {
        for(int i = 0; i < n; i++)
        {
            if(bookName[i].equalsIgnoreCase(book))
            {
                if(quantity[i] > 0)
                {
                    quantity[i]--;
                    System.out.println("Book Issued Successfully");
                }
                else
                {
                    System.out.println("Book Out of Stock");
                }
                return;
            }
        }
        System.out.println("Book Not Found");
    }

    void returnBook(String book)
    {
        for(int i = 0; i < n; i++)
        {
            if(bookName[i].equalsIgnoreCase(book))
            {
                quantity[i]++;
                System.out.println("Book Returned Successfully");
                return;
            }
        }
        System.out.println("Book Not Found");
    }

    void searchBook(String book)
    {
        for(int i = 0; i < n; i++)
        {
            if(bookName[i].equalsIgnoreCase(book))
            {
                System.out.println("Book Found");
                System.out.println("Book Name : " + bookName[i]);
                System.out.println("Quantity : " + quantity[i]);
                return;
            }
        }
        System.out.println("Book Not Found");
    }

    void displayBooks()
    {
        System.out.println("\n----- BOOK LIST -----");

        for(int i = 0; i < n; i++)
        {
            System.out.println(bookName[i] + " - " + quantity[i]);
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        LibrarySystem obj = new LibrarySystem();

        obj.addBooks();

        int choice;

        do
        {
            System.out.println("\n1. Issue Book");
            System.out.println("2. Return Book");
            System.out.println("3. Search Book");
            System.out.println("4. Display All Books");
            System.out.println("5. Exit");
            System.out.print("Enter Choice: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch(choice)
            {
                case 1:
                    System.out.print("Enter Book Name: ");
                    String issue = sc.nextLine();
                    obj.issueBook(issue);
                    break;

                case 2:
                    System.out.print("Enter Book Name: ");
                    String ret = sc.nextLine();
                    obj.returnBook(ret);
                    break;

                case 3:
                    System.out.print("Enter Book Name: ");
                    String search = sc.nextLine();
                    obj.searchBook(search);
                    break;

                case 4:
                    obj.displayBooks();
                    break;

                case 5:
                    System.out.println("Thank You");
                    break;

                default:
                    System.out.println("Invalid Choice");
            }

        } while(choice != 5);

        sc.close();
    }
}