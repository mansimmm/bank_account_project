#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountName;
    double balance;

public:
    BankAccount(string n, int accNum, double bal = 0.0) {
        accountName = n;
        accountNumber = accNum;
        balance = bal;
    }

    void displayMenu() {
        cout << "\n====== Bank Account System ======\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Account Information\n";
        cout << "4. Exit\n";
        cout << "=================================\n";
    }

    void getAccountInfo() {
        cout << "\n--- Account Information ---\n";
        cout << "Account Name: " << accountName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "----------------------------\n";
    }

    void deposit() {
        double amount;
        cout << "\nEnter the amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposit successful!\n";
            cout << "New Balance: $" << balance << endl;
        }
        else {
            cout << "Invalid amount. Please try again.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "\nEnter the amount to withdraw: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount. Please try again.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal denied.\n";
        }
        else {
            balance -= amount;
            cout << "\nWithdrawal successful!\n";
            cout << "Remaining Balance: $" << balance << endl;
        }
    }

    void start() {
        int choice;
        do {
            displayMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: getAccountInfo(); break;
            case 4: cout << "\nExiting the system. Thank you!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    string name;
    int accountNum;
    double initialBalance;

    cout << "Enter Account Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accountNum;

    cout << "Enter Initial Balance: $";
    cin >> initialBalance;

    BankAccount account(name, accountNum, initialBalance);
    account.start();

    return 0;
}
