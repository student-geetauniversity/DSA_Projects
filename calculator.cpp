#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void showMenu() {
    cout << "\n--- Advanced Calculator ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exponentiation (x^y)" << endl;
    cout << "6. Square Root" << endl;
    cout << "7. Modulo" << endl;
    cout << "8. View History" << endl;
    cout << "9. Clear History" << endl;
    cout << "10. Exit" << endl;
    cout << "Select an option: ";
}

void addToHistory(vector<string>& history, const string& entry) {
    history.push_back(entry);
}

void viewHistory(const vector<string>& history) {
    cout << "\n--- Calculation History ---" << endl;
    if (history.empty()) {
        cout << "No calculations yet." << endl;
    } else {
        for (const auto& entry : history) {
            cout << entry << endl;
        }
    }
}

int main() {
    int choice;
    double num1, num2;
    vector<string> history;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                addToHistory(history, to_string(num1) + " + " + to_string(num2) + " = " + to_string(num1 + num2));
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                addToHistory(history, to_string(num1) + " - " + to_string(num2) + " = " + to_string(num1 - num2));
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                addToHistory(history, to_string(num1) + " * " + to_string(num2) + " = " + to_string(num1 * num2));
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                    addToHistory(history, to_string(num1) + " / " + to_string(num2) + " = " + to_string(num1 / num2));
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 5:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                addToHistory(history, to_string(num1) + " ^ " + to_string(num2) + " = " + to_string(pow(num1, num2)));
                break;
            case 6:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    cout << "Result: " << sqrt(num1) << endl;
                    addToHistory(history, "sqrt(" + to_string(num1) + ") = " + to_string(sqrt(num1)));
                } else {
                    cout << "Error: Cannot calculate square root of a negative number!" << endl;
                }
                break;
            case 7:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
                addToHistory(history, to_string(static_cast<int>(num1)) + " % " + to_string(static_cast<int>(num2)) + " = " + to_string(static_cast<int>(num1) % static_cast<int>(num2)));
                break;
            case 8:
                viewHistory(history);
                break;
            case 9:
                history.clear();
                cout << "History cleared." << endl;
                break;
            case 10:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}
