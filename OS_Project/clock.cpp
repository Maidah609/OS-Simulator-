#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

// Brighter Color Codes
#define RESET      "\033[0m"
#define CYAN       "\033[1;96m"
#define BOLDCYAN   "\033[1;96m"
#define WHITE      "\033[1;97m"
#define BRIGHTRED  "\033[1;91m"

int main() {
    while (true) {
        system("clear");  // clear terminal output

        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);

        // Colorful header
        cout << WHITE << "==============================\n";
        cout << "      CURRENT SYSTEM TIME     \n";
        cout << "==============================\n" << RESET;

        // Time in bright cyan
        cout << CYAN << ctime(&now_time) << RESET;

        // Exit message
        cout << BRIGHTRED << "\nPress Ctrl+C to exit." << RESET << endl;

        // Wait for 1 second before updating
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}

