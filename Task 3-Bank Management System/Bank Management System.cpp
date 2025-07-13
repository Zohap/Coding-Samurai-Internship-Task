#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string number, double bal = 0.0) {
        accountHolder = name;
        accountNumber = number;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else cout << "Invalid deposit amount!\n";
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Invalid or insufficient funds!\n";
    }

    void displayBalance() const {
        cout << "\nAccount Holder: " << accountHolder
             << "\nAccount Number: " << accountNumber
             << "\nBalance: $" << balance << "\n";
    }

    void transfer(BankAccount &receiver, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.deposit(amount);
            cout << "Transferred $" << amount << " to " << receiver.accountHolder << "\n";
        } else {
            cout << "Transfer failed.\n";
        }
    }
};

int main() {
    string name1, accNum1, name2, accNum2;
    double bal1, bal2;

    cout << "Enter details for Account 1:\n";
    cout << "Name: "; cin >> name1;
    cout << "Account Number: "; cin >> accNum1;
    cout << "Initial Balance: $"; cin >> bal1;

    cout << "\nEnter details for Account 2:\n";
    cout << "Name: "; cin >> name2;
    cout << "Account Number: "; cin >> accNum2;
    cout << "Initial Balance: $"; cin >> bal2;

    BankAccount acc1(name1, accNum1, bal1);
    BankAccount acc2(name2, accNum2, bal2);

    int choice;
    double amount;

    do {
    cout << "\n===== MENU =====\n";
    cout << "1. Deposit to " << name1 << "\n";
    cout << "2. Withdraw from " << name1 << "\n";
    cout << "3. Show Balance of " << name1 << "\n";
    cout << "4. Transfer from " << name1 << " to " << name2 << "\n";
    cout << "5. Show Balance of " << name2 << "\n";  // ✅ NEW OPTION
    cout << "0. Exit\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter amount to deposit: $";
        cin >> amount;
        acc1.deposit(amount);
        break;
    case 2:
        cout << "Enter amount to withdraw: $";
        cin >> amount;
        acc1.withdraw(amount);
        break;
    case 3:
        acc1.displayBalance();
        break;
    case 4:
        cout << "Enter amount to transfer: $";
        cin >> amount;
        acc1.transfer(acc2, amount);
        break;
    case 5:
        acc2.displayBalance();  // ✅ Display second account's details
        break;
    case 0:
        cout << "Exiting the system. Thank you!\n";
        break;
    default:
        cout << "Invalid choice.\n";
    }
} while (choice != 0);


    return 0;
}
