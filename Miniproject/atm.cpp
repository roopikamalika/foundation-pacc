#include <iostream>
using namespace std;

class Bank {
public:
    string accountName;
    string username;
    string password;
    float balance;

    void signup() {
        cout << "\n===== SIGN UP =====\n";
        cout << "Create Username: ";
        cin >> username;
        cout << "Create Password: ";
        cin >> password;
        cout << "Account Holder Name: ";
        cin >> accountName;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!\n";
    }

    bool login() {
        string user, pass;

        cout << "\n===== LOGIN =====\n";
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            cout << "\nLogin Successful!\n";
            return true;
        } else {
            cout << "\nInvalid Username or Password!\n";
            return false;
        }
    }

    void deposit() {
        float amount;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount Deposited Successfully.\n";
        cout << "Current Balance: " << balance << endl;
    }

    void withdraw() {
        float amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        if (balance - amount < 100) {
            cout << "Minimum Balance of 100 must be maintained.\n";
        } else {
            balance -= amount;
            cout << "Amount Withdrawn Successfully.\n";
            cout << "Current Balance: " << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Bank b1;

    b1.signup();

    if (!b1.login()) {
        cout << "Access Denied!\n";
        return 0;
    }

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b1.deposit();
                break;

            case 2:
                b1.withdraw();
                break;

            case 3:
                b1.checkBalance();
                break;

            case 4:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}