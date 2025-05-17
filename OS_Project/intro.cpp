// intro.cpp
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLDWHITE "\033[1m\033[37m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDYELLOW "\033[1m\033[33m"

// Decorative line
void printLine() {
    cout << BOLDWHITE << "======================================================================" << RESET << endl;
}

bool login() {
    system("clear");
    string SAName;
    string SAPass;
    int gen_captcha = 0, Input_captcha = 0;

    cout << BOLDGREEN << "\n\t\t╔═══════════════════════════════════════════╗" << RESET << endl;
    cout << BOLDGREEN << "\t\t║               LOGIN PORTAL                ║" << RESET << endl;
    cout << BOLDGREEN << "\t\t╚═══════════════════════════════════════════╝" << RESET << endl;

    cout << BOLDCYAN << "\n\t\tUser Name : " << RESET;
    cin >> SAName;
    cout << BOLDCYAN << "\t\tPassword  : " << RESET;
    cin >> SAPass;

    srand(time(0));
    gen_captcha = rand() % 1000;
    cout << YELLOW << endl << "\t\tEnter this number below : " << gen_captcha << RESET << endl;
    cout << BOLDCYAN << "\t\tEnter the above number  : " << RESET;
    cin >> Input_captcha;

    if (SAName == "user" && SAPass == "pass" && gen_captcha == Input_captcha) {
        cout << GREEN << endl << "\t\t\t\t | Verifying User | " << RESET << endl;
        cout << "\t\t\t\t ";
        sleep(2);
        cout << GREEN << "......" << RESET;
        cout << endl << endl << BOLDGREEN << "\t\t\t   ✓ User Verified. Welcome! :)\n" << RESET << endl;
        sleep(2);
        return true;
    } else {
        cout << RED << endl << "\t\t\t\t | Verifying User | " << RESET << endl;
        cout << "\t\t\t\t ";
        for (int s = 1; s < 4; s++) {
            sleep(1);
            cout << RED << "......" << RESET;
        }
        cout << endl << endl << BOLDRED << "\t\t\t   ✗ Access Denied. Please try again. :(\n" << RESET << endl;
        sleep(2);
        return false;
    }
}

int main() {
    system("clear");
    string letters[9] = {
        "       OOOOOOOO00O SSSSSSSSSS",
        "       O         O S",
        "       O         O S",
        "       O         O S",
        "       O         O SSSSSSSSS",
        "       O         O         S",
        "       O         O         S",
        "       O         O         S",
        "       OOOOOOOOOOO SSSSSSSSS"
    };

    cout << BOLDYELLOW << "\n\n\n\t\t\t\tWelcome to\n\n" << RESET;
    for (int i = 0; i < 9; i++) {
        cout << BOLDCYAN << "\t\t   " << letters[i] << RESET << endl;
    }

    printLine();
    cout << BOLDWHITE << "\t\tCREDITS:  " << RESET << endl;
    cout << BOLDGREEN << "\t\t | MAIDAH NASIR (23f-0764)" << RESET << endl;
    cout << BOLDGREEN << "\t\t | ANZA NASEER (23f-0631)" << RESET << endl;
    printLine();

    cout << BOLDWHITE << endl << "\t\t\t       | Loading | " << RESET << endl;
    cout << "\t\t\t        ";
    for (int s = 0; s < 4; s++) {
        sleep(1);
        cout << CYAN << ".." << RESET;
    }

    cout << endl << endl << BOLDWHITE << "Press Enter to continue..." << RESET << endl;
    cin.ignore(); // discard leftover newline
    cin.get();    // wait for Enter

    system("clear");

    // Login loop
    while (!login());

    cout << endl << BOLDWHITE << "Press Enter to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("clear");

    // DO NOT call main.cpp here. Just end cleanly.
    cout << BOLDGREEN << "\nLogin successful. Returning to main menu..." << RESET << endl;
    sleep(2);
    return 0;
}

