#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

// Color codes (Green theme + Red for errors)
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define RED     "\033[31m"

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << BOLDGREEN << "\t\t\t\t<" << string(length + 8, '=') << ">\n";
    cout << "\t\t\t\t" << "=   " << headerText << "   =\n";
    cout << "\t\t\t\t<" << string(length + 8, '=') << ">" << RESET << endl;
}

bool copyFileContent(const string& sourceFile, const string& targetFile) {
    ifstream source(sourceFile);
    if (!source) {
        cout << RED << "Error: Failed to open source file " << sourceFile << RESET << endl;
        return false;
    }

    ofstream target(targetFile);
    if (!target) {
        cout << RED << "Error: Failed to open target file " << targetFile << RESET << endl;
        source.close();
        return false;
    }

    target << source.rdbuf();

    if (source.bad() || target.bad()) {
        cout << RED << "Error: Failed to copy file content" << RESET << endl;
        source.close();
        target.close();
        return false;
    }

    source.close();
    target.close();

    cout << GREEN << "✅ File content copied successfully" << RESET << endl;
    return true;
}

int main() {
    printHeader("File Copy Program");

    char startChoice;
    cout << BOLDGREEN << "\nDo you want to copy a file? (Y/N): " << RESET;
    cin >> startChoice;

    if (startChoice != 'Y' && startChoice != 'y') {
        cout << GREEN << "Exiting the program." << RESET << endl;
        return 0;
    }
    
    string sourceFile, targetFile;

    cout << BOLDGREEN << "\nEnter the Path of Source File: " << RESET;
    cin >> sourceFile;

    cout << BOLDGREEN << "Enter the Path of Target File: " << RESET;
    cin >> targetFile;

    if (copyFileContent(sourceFile, targetFile)) {
        cout << GREEN << "✅ File content copied successfully to " << targetFile << RESET << endl;
        sleep(2);
    } else {
        cout << RED << "❌ File content copy failed" << RESET << endl;
    }

    cout << BOLDGREEN << "\nPress Enter to exit..." << RESET << endl;
    cin.ignore();  // Clear input buffer
    cin.get();     // Wait for Enter key

    return 0;
}

