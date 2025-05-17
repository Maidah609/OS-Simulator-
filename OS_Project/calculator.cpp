#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <unistd.h>
using namespace std;

// Bright Color Codes
#define RESET      "\033[0m"
#define RED        "\033[1;91m"
#define GREEN      "\033[1;92m"
#define YELLOW     "\033[1;93m"
#define BLUE       "\033[1;94m"
#define MAGENTA    "\033[1;95m"
#define CYAN       "\033[1;96m"
#define BOLDWHITE  "\033[1;97m"

// Function to safely input a double (validates numeric input)
double inputNumber(const string& prompt) {
    double num;
    while (true) {
        cout << CYAN << prompt << RESET;
        cin >> num;

        if (cin.fail()) {
            cerr << RED << "Error: Invalid input. Please enter a valid number.\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard leftover input
            return num;
        }
    }
}

// Function to safely input menu choice
char inputMenuChoice() {
    string input;
    cout << YELLOW << "Enter your choice: " << RESET;
    getline(cin, input);

    if (input.length() == 1 && (isdigit(input[0]) || input[0] == 'q' || input[0] == 'Q')) {
        return input[0];
    } else {
        return '\0';  // invalid input
    }
}

// Function to print a colorful menu header
void printHeader(const string& text) {
    cout << BOLDWHITE << "\n\t< " << string(text.length() + 6, '=') << " >\n";
    cout << "\t|   " << text << "   |\n";
    cout << "\t< " << string(text.length() + 6, '=') << " >\n\n" << RESET;
}

int main() {
    double num1, num2, result;
    char op;

    while (true) {
        system("clear");  // Clear screen each time for a fresh interface
        printHeader("CALCULATOR MENU");

        // Display the menu options with vivid colors
        cout << GREEN << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Exponentiation (^)\n";
        cout << "6. Modulus (%)\n";
        cout << RED << "Q/q. Quit\n" << RESET;

        op = inputMenuChoice();

        if (op == 'q' || op == 'Q') {
            cout << MAGENTA << "\nExiting the calculator. Goodbye!\n" << RESET;
            break;
        }

        if (op >= '1' && op <= '6') {
            num1 = inputNumber("Enter the first number: ");
            num2 = inputNumber("Enter the second number: ");

            cout << BLUE << "\n--- Calculation ---\n" << RESET;
            switch (op) {
                case '1':
                    result = num1 + num2;
                    cout << GREEN << num1 << " + " << num2 << " = " << result << endl << RESET;
                    break;
                case '2':
                    result = num1 - num2;
                    cout << GREEN << num1 << " - " << num2 << " = " << result << endl << RESET;
                    break;
                case '3':
                    result = num1 * num2;
                    cout << GREEN << num1 << " * " << num2 << " = " << result << endl << RESET;
                    break;
                case '4':
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << GREEN << num1 << " / " << num2 << " = " << result << endl << RESET;
                    } else {
                        cerr << RED << "Error: Division by zero.\n" << RESET;
                    }
                    break;
                case '5':
                    result = pow(num1, num2);
                    cout << GREEN << num1 << " ^ " << num2 << " = " << result << endl << RESET;
                    break;
                case '6':
                    if (num2 != 0) {
                        result = fmod(num1, num2);
                        cout << GREEN << num1 << " % " << num2 << " = " << result << endl << RESET;
                    } else {
                        cerr << RED << "Error: Modulus by zero.\n" << RESET;
                    }
                    break;
            }

            cout << YELLOW << "\nPress Enter to continue...";
            cin.get();
        } else {
            cerr << RED << "Invalid menu choice. Please select a valid option.\n" << RESET;
            cout << YELLOW << "Press Enter to continue...";
            cin.get();
        }
    }

    return 0;
}

