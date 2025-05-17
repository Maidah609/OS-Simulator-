#include <iostream>
#include <cstdlib>

using namespace std;

// Color codes
#define RESET        "\033[0m"
#define BRIGHT_RED   "\033[1;91m"
#define BRIGHT_GREEN "\033[1;92m"
#define BRIGHT_YELLOW "\033[1;93m"
#define BRIGHT_CYAN  "\033[1;96m"

int main() {
    string filename;
    cout << BRIGHT_CYAN << "🎵 Enter the name of the audio file (without .mp3): " << RESET;
    cin >> filename;

    string command;

    // Try VLC
    if (system("which vlc > /dev/null 2>&1") == 0) {
        command = "vlc \"" + filename + ".mp3\"";
        cout << BRIGHT_GREEN << "▶ Playing with VLC..." << RESET << endl;
        system(command.c_str());
    }
    // Try CVLC
    else if (system("which cvlc > /dev/null 2>&1") == 0) {
        command = "cvlc \"" + filename + ".mp3\"";
        cout << BRIGHT_GREEN << "▶ Playing with CVLC..." << RESET << endl;
        system(command.c_str());
    }
    // Try mpg123
    else if (system("which mpg123 > /dev/null 2>&1") == 0) {
        command = "mpg123 \"" + filename + ".mp3\"";
        cout << BRIGHT_GREEN << "▶ Playing with mpg123..." << RESET << endl;
        system(command.c_str());
    }
    // No supported player
    else {
        cout << BRIGHT_RED << "❌ No supported audio player (vlc/cvlc/mpg123) found." << RESET << endl;
        cout << BRIGHT_YELLOW << "💡 Please install one of them and try again." << RESET << endl;
    }

    return 0;
}

