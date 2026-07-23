#include <iostream>
#include <limits>
using namespace std;

int main() {
    int pin[1] = { 1234 };  // ATM PIN
    int enteredPin;
    int attempts = 0;
    int balance = 5000;
    int choice, amount;

    // PIN check loop
    while (attempts < 3) {
        cout << "Enter PIN: ";
        if (!(cin >> enteredPin)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (enteredPin == pin[0]) {
            break;
        } else {
            cout << "Wrong PIN!\n";
            attempts++;
        }
    }

    if (attempts == 3) {
        cout << "ATM Blocked! Too many wrong attempts.";
        return 0;
    }

    // ATM menu loop
    while (true) {
        cout << "\n\n--- ATM MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Cash\n";
        cout << "3. Withdraw Cash\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Enter a number.";
            continue;
        }

        if (choice == 1) {
            cout << "Current Balance: " << balance;
        } 
        else if (choice == 2) {
            cout << "Enter amount to deposit: ";
            if (!(cin >> amount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input!";
                continue;
            }

            if (amount <= 0) {
                cout << "Invalid Amount! Must be greater than 0.";
            } else {
                balance = balance + amount;
                cout << "Amount Deposited Successfully.";
            }
        } 
        else if (choice == 3) {
            cout << "Enter amount to withdraw: ";
            if (!(cin >> amount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input!";
                continue;
            }

            if (amount <= 0) {
                cout << "Invalid Amount! Must be greater than 0.";
            } else if (amount <= balance) {
                balance = balance - amount;
                cout << "Please collect your cash.";
            } else {
                cout << "Insufficient Balance!";
            }
        } 
        else if (choice == 4) {
            cout << "Thank you for using ATM.";
            break;
        } 
        else {
            cout << "Invalid Choice!";
        }
    }

    return 0;
}
