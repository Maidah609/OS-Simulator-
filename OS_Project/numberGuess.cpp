#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
using namespace std;

// Bright Color codes
#define RESET       "\033[0m"
#define BRIGHT_RED  "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_MAGENTA "\033[1;95m"
#define BRIGHT_CYAN "\033[1;96m"
#define BOLDWHITE   "\033[1;97m"

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << BOLDWHITE << "\t\t\t\t<" << string(length + 8, '=') << ">" << endl;
    cout << "\t\t\t\t" << "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<" << string(length + 8, '=') << ">" << RESET;
}

int getValidatedGuess() {
    int guess;
    while (true) {
        cout << BRIGHT_YELLOW << "\nEnter your guess (1-100): " << RESET;
        cin >> guess;

        if (cin.fail() || guess < 1 || guess > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << BRIGHT_RED << "Invalid input. Please enter a number between 1 and 100." << RESET << endl;
        } else {
            return guess;
        }
    }
}

int main() {
    srand(time(0));
    char playAgain;

    do {
        system("clear");
        const int targetNumber = rand() % 100 + 1;
        int guess;
        int attempts = 0;

        printHeader("Number Guessing Game");
        cout << BRIGHT_CYAN << "\n\nI have selected a number between 1 and 100." << RESET << endl;

        do {
            guess = getValidatedGuess();
            attempts++;

            if (guess > targetNumber) {
                cout << BRIGHT_RED << "Too high! " << RESET;
                if (guess - targetNumber <= 10)
                    cout << BRIGHT_MAGENTA << "But you are close! Try again.\n" << RESET;
                else
                    cout << BRIGHT_CYAN << "Try again.\n" << RESET;
            } else if (guess < targetNumber) {
                cout << BRIGHT_RED << "Too low! " << RESET;
                if (targetNumber - guess <= 10)
                    cout << BRIGHT_MAGENTA << "But you are close! Try again.\n" << RESET;
                else
                    cout << BRIGHT_CYAN << "Try again.\n" << RESET;
            } else {
                cout << BRIGHT_GREEN << "\n🎉 Congratulations! You guessed the number " << targetNumber
                     << " in " << attempts << " attempts!\n" << RESET;
                break;
            }
        } while (true);

        cout << BRIGHT_YELLOW << "\nDo you want to play again? (y/n): " << RESET;
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << BRIGHT_GREEN << "\nThank you for playing!\n" << RESET;
    sleep(2);
    return 0;
}

