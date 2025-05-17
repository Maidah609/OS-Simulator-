#include <iostream>
#include <cstdio>
#include <cstdlib>
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

int main() {
    printHeader("File Deletion Program");

    int status;
    char fileName[256];   // Increased size to support longer file names

    char startChoice;
    cout << BOLDGREEN << "\nDo you want to delete a file? (Y/N): " << RESET;
    cin >> startChoice;

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << GREEN << "Exiting the program.\n" << RESET;
        return 0;
    }

    while (true) {
        cout << BOLDGREEN << "\nEnter the Name of File: " << RESET;
        cin >> fileName;

        status = remove(fileName);
        if (status == 0)
            cout << GREEN << "✅ File deleted successfully!\n" << RESET;
        else
            cout << RED << "❌ Error: Could not delete the file!\n" << RESET;

        char choice;
        cout << BOLDGREEN << "\nDo you want to delete another file? (Y/N): " << RESET;
        cin >> choice;

        if (choice != 'Y' && choice != 'y') {
            cout << GREEN << "Exiting the program.\n" << RESET;
            break;
        }
    }

    return 0;
}

