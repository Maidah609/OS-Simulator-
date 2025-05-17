#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
using namespace std;

// Bright terminal color codes
#define RESET        "\033[0m"
#define BRIGHT_RED   "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_CYAN  "\033[1;96m"
#define BRIGHT_WHITE "\033[1;97m"

int getValidChoice() {
    int choice;
    while (true) {
        cout << BRIGHT_YELLOW << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): " << RESET;
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << BRIGHT_RED << "Invalid input. Please enter 0, 1, or 2.\n" << RESET;
        } else {
            return choice;
        }
    }
}

int main() {
    srand(time(0));
    string choices[] = { "Rock 🪨", "Paper 📄", "Scissors ✂️" };

    cout << BRIGHT_WHITE << "======================================" << endl;
    cout << "       Welcome to Rock, Paper, Scissors!" << endl;
    cout << "======================================\n" << RESET;

    int wins = 0, losses = 0, ties = 0;

    while (true) {
        int playerChoice = getValidChoice();
        int computerChoice = rand() % 3;

        cout << BRIGHT_CYAN << "You chose: " << choices[playerChoice] << RESET << endl;
        cout << BRIGHT_CYAN << "Computer chose: " << choices[computerChoice] << RESET << endl;

        if (playerChoice == computerChoice) {
            cout << BRIGHT_YELLOW << "It's a tie!\n" << RESET;
            ties++;
        } else if ((playerChoice == 0 && computerChoice == 2) ||
                   (playerChoice == 1 && computerChoice == 0) ||
                   (playerChoice == 2 && computerChoice == 1)) {
            cout << BRIGHT_GREEN << "🎉 Congratulations! You win!\n" << RESET;
            wins++;
        } else {
            cout << BRIGHT_RED << "😢 Sorry, you lose. Better luck next time!\n" << RESET;
            losses++;
        }

        cout << "\n" << BRIGHT_WHITE << "Score → Wins: " << BRIGHT_GREEN << wins
             << RESET << BRIGHT_WHITE << " | Losses: " << BRIGHT_RED << losses
             << RESET << BRIGHT_WHITE << " | Ties: " << BRIGHT_YELLOW << ties << RESET << endl;

        char playAgain;
        cout << BRIGHT_CYAN << "Do you want to play again? (y/n): " << RESET;
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << BRIGHT_GREEN << "\nThanks for playing! Goodbye!\n" << RESET;
            break;
        }

        cout << "\n" << BRIGHT_WHITE << "--------------------------------------\n" << RESET;
    }

    return 0;
}

