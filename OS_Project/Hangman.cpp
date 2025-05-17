#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

// Brighter ANSI Color Codes
#define RESET        "\033[0m"
#define BRIGHT_RED   "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_BLUE  "\033[1;94m"
#define BOLD_WHITE   "\033[1;97m"

void printHangman(int attempts) {
    cout << BRIGHT_RED;
    switch(attempts) {
        case 1:
            cout << "  O" << endl;
            break;
        case 2:
            cout << "  O" << endl;
            cout << "  |" << endl;
            break;
        case 3:
            cout << "  O" << endl;
            cout << " \\|" << endl;
            break;
        case 4:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            break;
        case 5:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " /" << endl;
            break;
        case 6:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " / \\" << endl;
            break;
    }
    cout << RESET;
}

int main() {
    string secretWord;
    string guessedWord;
    char incorrectLetters[6];

    int maxAttempts = 6;
    int attempts = 0;

    cout << BOLD_WHITE << "\t\t\t=========================" << endl;
    cout << "\t\t\t      WELCOME TO HANGMAN" << endl;
    cout << "\t\t\t=========================" << RESET << endl;

    cout << BRIGHT_BLUE << "You have to guess the secret word.\n";
    cout << "Enter the secret word: " << RESET;
    cin >> secretWord;

    guessedWord = string(secretWord.length(), '_');

    system("clear");  // Clear screen to hide the word

    while (true) {
        cout << "\n" << BOLD_WHITE << "==============================" << RESET << endl;
        cout << BRIGHT_YELLOW << "Guessed word: " << guessedWord << RESET << endl;

        printHangman(attempts);

        cout << BRIGHT_BLUE << "Incorrect letters: " << RESET;
        for (int i = 0; i < attempts; i++) {
            cout << BRIGHT_RED << incorrectLetters[i] << " " << RESET;
        }
        cout << endl;

        cout << BRIGHT_BLUE << "Attempts left: " << RESET << (maxAttempts - attempts) << endl;

        cout << "\n" << BRIGHT_BLUE << "Guess a letter: " << RESET;
        char guess;
        cin >> guess;

        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            incorrectLetters[attempts] = guess;
            attempts++;
        }

        if (guessedWord == secretWord) {
            cout << BRIGHT_GREEN << "\n🎉 Congratulations! You guessed the word: " << guessedWord << RESET << endl;
            break;
        }

        if (attempts == maxAttempts) {
            cout << BRIGHT_RED << "\n💀 You lost! The word was: " << secretWord << RESET << endl;
            break;
        }
    }

    sleep(4);
    return 0;
}

