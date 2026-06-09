#include <iostream>
using namespace std;

class TrainTicket
{
public:
    string name;
    int age;
    long long aadhar;
    int passengerID;
    bool booked;

    static int nextID;

    TrainTicket()
    {
        booked = false;
    }

    void bookTicket()
    {
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Aadhar Number: ";
        cin >> aadhar;

        long long temp = aadhar;
        int digits = 0;

        while(temp > 0)
        {
            digits++;
            temp /= 10;
        }

        if(digits == 12)
        {
            int amount = 500;
            int paid;

            cout << "\nAadhar Verification Successful!" << endl;
            cout << "Ticket Amount: Rs." << amount << endl;

            cout << "Enter Payment Amount: ";
            cin >> paid;

            if(paid >= amount)
            {
                passengerID = nextID++;
                booked = true;

                cout << "\nPayment Successful!" << endl;
                cout << "Ticket Booked Successfully!" << endl;
                cout << "Passenger ID: " << passengerID << endl;

                if(paid > amount)
                {
                    cout << "Balance Amount: Rs." << paid - amount << endl;
                }
            }
            else
            {
                cout << "Insufficient Payment! Ticket Not Booked." << endl;
            }
        }
        else
        {
            cout << "\nInvalid Aadhar Number!" << endl;
        }
    }

    void display()
    {
        if(booked)
        {
            cout << "\nPassenger ID : " << passengerID;
            cout << "\nName         : " << name;
            cout << "\nAge          : " << age;
            cout << "\nAadhar No    : " << aadhar << endl;
        }
    }
};

int TrainTicket::nextID = 1;

int main()
{
    TrainTicket t[100];
    int count = 0;
    int choice, id;
    bool found;

    do
    {
        cout << "\n\n===== TRAIN TICKET SYSTEM =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. Cancel Ticket";
        cout << "\n3. View Passengers";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                t[count].bookTicket();
                if(t[count].booked)
                {
                    count++;
                }
                break;

            case 2:
                cout << "\nEnter Passenger ID to Cancel: ";
                cin >> id;

                found = false;

                for(int i = 0; i < count; i++)
                {
                    if(t[i].passengerID == id && t[i].booked)
                    {
                        t[i].booked = false;
                        cout << "Ticket Cancelled Successfully!" << endl;
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "Passenger ID Not Found!" << endl;
                }
                break;

            case 3:
                cout << "\n----- Passenger Details -----" << endl;

                for(int i = 0; i < count; i++)
                {
                    t[i].display();
                }
                break;

            case 4:
                cout << "\nThank You!" << endl;
                break;

            default:
                cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}