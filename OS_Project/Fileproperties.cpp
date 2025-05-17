#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <ctime>

using namespace std;

// Color codes (Blue/Cyan theme + Red for errors)
#define RESET      "\033[0m"
#define CYAN       "\033[36m"
#define BOLDCYAN   "\033[1m\033[36m"
#define BLUE       "\033[34m"
#define BOLDBLUE   "\033[1m\033[34m"
#define RED        "\033[31m"

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << BOLDBLUE << "\t\t\t\t<" << string(length + 8, '=') << ">" << endl;
    cout << "\t\t\t\t" << "=   " << headerText << "   =" << endl;
    cout << "\t\t\t\t<" << string(length + 8, '=') << ">" << RESET << endl;
}

int main() {
    printHeader("File Information Program");

    string filename;
    while (true) {
        cout << BOLDCYAN << "\nEnter file name (or 'exit' to quit): " << RESET;
        cin >> filename;

        if (filename == "exit" || filename == "Exit" || filename == "EXIT") {
            cout << CYAN << "Exiting the program.\n" << RESET;
            break;
        }

        struct stat fileStat;

        if (stat(filename.c_str(), &fileStat) < 0) {
            cout << RED << "❌ Failed to get file properties.\n" << RESET;
            continue;
        }

        cout << BOLDBLUE << "\n📄 File Information:\n" << RESET;
        cout << CYAN << "File name: " << RESET << filename << endl;
        cout << CYAN << "Size: " << RESET << fileStat.st_size << " bytes" << endl;
        cout << CYAN << "Owner ID: " << RESET << fileStat.st_uid << endl;
        cout << CYAN << "Group ID: " << RESET << fileStat.st_gid << endl;
        cout << CYAN << "Permissions (raw mode): " << RESET << fileStat.st_mode << endl;
        cout << CYAN << "Last access time: " << RESET << ctime(&fileStat.st_atime);
        cout << CYAN << "Last modification time: " << RESET << ctime(&fileStat.st_mtime);
        cout << CYAN << "Last status change time: " << RESET << ctime(&fileStat.st_ctime);

        char choice;
        cout << BOLDCYAN << "\nDo you want to check another file? (Y/N): " << RESET;
        cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            cout << CYAN << "Exiting the program.\n" << RESET;
            break;
        }
    }

    return 0;
}

