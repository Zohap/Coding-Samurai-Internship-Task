#include <iostream>
using namespace std;

// Function declarations
void showMenu();
double calculate(double num1, double num2, char op);

int main() {
    double num1, num2, result;
    char op;
    char choice;

    cout << "===============================" << endl;
    cout << "      SIMPLE C++ CALCULATOR    " << endl;
    cout << "===============================\n" << endl;

    do {
        showMenu();

        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        result = calculate(num1, num2, op);
        cout << "\nResult: " << num1 << " " << op << " " << num2 << " = " << result << endl;

        // Ask if the user wants to continue
        cout << "\nWould you like to perform another calculation? (Y/N): ";
        cin >> ws >> choice;

        // Input validation loop
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> ws >> choice;
        }

        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}

// Display available operations
void showMenu() {
    cout << "\nSelect an operation to perform:\n";
    cout << " [ + ] Addition\n";
    
    cout << " [ - ] Subtraction\n";
    cout << " [ * ] Multiplication\n";
    cout << " [ / ] Division\n";
}

// Perform calculation
double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
        default:
            cout << "Invalid operator!" << endl;
            return 0;
    }
}