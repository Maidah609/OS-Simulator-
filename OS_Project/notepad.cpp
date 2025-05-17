#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Brighter Color Codes
#define RESET        "\033[0m"
#define BRIGHT_RED   "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_CYAN  "\033[1;96m"
#define BOLD_WHITE   "\033[1;97m"

void createNewFile() {
    fstream file;
    string fileName;

    cout << BRIGHT_YELLOW << "Enter the file name (without extension): " << RESET;
    cin >> fileName;

    file.open(fileName + ".txt", ios::out);
    if (!file) {
        cout << BRIGHT_RED << "Error in creating file!" << RESET << endl;
    } else {
        cout << BRIGHT_GREEN << "File '" << fileName << ".txt' created successfully." << RESET << endl;
        file.close();
    }
}

void editExistingFile() {
    string fileName;
    cout << BRIGHT_YELLOW << "Enter the file name (with extension): " << RESET;
    cin >> fileName;

    fstream file(fileName, ios::in | ios::out);
    if (!file.is_open()) {
        cout << BRIGHT_RED << "Error opening file! Make sure the file exists in the same folder." << RESET << endl;
        return;
    }

    // Display file contents
    string line;
    cout << BRIGHT_CYAN << "\nFile contents:" << RESET << endl;
    int lineNumber = 1;
    while (getline(file, line)) {
        cout << BOLD_WHITE << lineNumber << ": " << RESET << line << endl;
        lineNumber++;
    }

    // Prepare to append text
    file.clear();
    file.seekp(0, ios::end);

    cout << BRIGHT_CYAN << "\nEnter text to add (Enter '#' on a new line to save and exit editing):" << RESET << endl;
    string input;
    cin.ignore();

    while (getline(cin, input)) {
        if (input == "#") break;
        file << input << endl;
    }

    cout << BRIGHT_GREEN << "Text saved. Exiting editing mode." << RESET << endl;
    file.close();
}

int main() {
    while (true) {
        cout << BOLD_WHITE << "\n============================" << RESET << endl;
        cout << BRIGHT_CYAN << "Choose an option:" << RESET << endl;
        cout << BRIGHT_CYAN << "1. Create a new file" << RESET << endl;
        cout << BRIGHT_CYAN << "2. Edit an existing file" << RESET << endl;
        cout << BRIGHT_CYAN << "3. Exit" << RESET << endl;

        cout << BRIGHT_YELLOW << "Enter your choice: " << RESET;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createNewFile();
                break;
            case 2:
                editExistingFile();
                break;
            case 3:
                cout << BRIGHT_GREEN << "Exiting program." << RESET << endl;
                return 0;
            default:
                cout << BRIGHT_RED << "Invalid choice! Please enter 1, 2, or 3." << RESET << endl;
        }
    }

    return 0;
}

