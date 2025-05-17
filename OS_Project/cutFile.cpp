#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

// Color codes (Green theme + Red for errors)
#define RESET     "\033[0m"
#define GREEN     "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define RED       "\033[31m"

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << BOLDGREEN << "\t\t\t\t<" << string(length + 8, '=') << ">" << endl;
    cout << "\t\t\t\t" << "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<" << string(length + 8, '=') << ">" << RESET << endl;
}

bool cutFileContent(const string& sourceFile, const string& targetFile) {
    ifstream source(sourceFile);
    if (!source) {
        cout << RED << "❌ Error: Source file '" << sourceFile << "' not found.\n" << RESET;
        return false;
    }

    ofstream target(targetFile);
    if (!target) {
        cout << RED << "❌ Error: Failed to open target file '" << targetFile << "'\n" << RESET;
        source.close();
        return false;
    }

    target << source.rdbuf();

    if (source.bad() || target.bad()) {
        cout << RED << "❌ Error: Failed to cut file content.\n" << RESET;
        source.close();
        target.close();
        return false;
    }

    source.close();
    target.close();

    if (remove(sourceFile.c_str()) != 0) {
        cout << RED << "❌ Error: Failed to delete source file '" << sourceFile << "'\n" << RESET;
        return false;
    }

    cout << GREEN << "✅ File content cut successful.\n" << RESET;
    return true;
}

int main() {
    printHeader("File Content Cut Program");

    char startChoice;
    cout << BOLDGREEN << "\nDo you want to cut a file? (Y/N): " << RESET;
    cin >> startChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << GREEN << "Exiting the program.\n" << RESET;
        return 0;
    }

    while (true) {
        string sourceFile, targetFile;

        // Prompt for valid source file
        while (true) {
            cout << BOLDGREEN << "\nEnter the Path of Source File: " << RESET;
            getline(cin, sourceFile);

            ifstream source(sourceFile);
            if (source) {
                source.close();
                break;
            } else {
                cout << RED << "❌ Error: Source file '" << sourceFile << "' not found. Please try again.\n" << RESET;
            }
        }

        cout << BOLDGREEN << "Enter the Path of Target File: " << RESET;
        getline(cin, targetFile);

        if (cutFileContent(sourceFile, targetFile)) {
            char choice;
            cout << BOLDGREEN << "\nDo you want to perform another operation?\n"
                                "1. Cut another file\n"
                                "2. Exit program\n"
                                "Enter your choice (1/2): " << RESET;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == '1') {
                continue;
            } else {
                cout << GREEN << "Exiting the program.\n" << RESET;
                break;
            }
        } else {
            char choice;
            cout << BOLDGREEN << "\nDo you want to try again?\n"
                                "1. Yes\n"
                                "2. Exit program\n"
                                "Enter your choice (1/2): " << RESET;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == '1') {
                continue;
            } else {
                cout << GREEN << "Exiting the program.\n" << RESET;
                break;
            }
        }
    }

    return 0;
}

