#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Color codes
#define RESET         "\033[0m"
#define BRIGHT_GREEN  "\033[1;92m"
#define BRIGHT_RED    "\033[1;91m"
#define BRIGHT_CYAN   "\033[1;96m"
#define BRIGHT_YELLOW "\033[1;93m"

int main() {
    string filename;
    cout << BRIGHT_CYAN << "🎬 Enter the name of the video file (without .mp4): " << RESET;
    cin >> filename;
    string fullFile = "\"" + filename + ".mp4\"";
    string command;

    // Check for VLC
    if (system("which vlc > /dev/null 2>&1") == 0) {
        command = "vlc " + fullFile;
        cout << BRIGHT_GREEN << "▶ Playing with VLC..." << RESET << endl;
        system(command.c_str());
    }
    // Check for CVLC
    else if (system("which cvlc > /dev/null 2>&1") == 0) {
        command = "cvlc " + fullFile;
        cout << BRIGHT_GREEN << "▶ Playing with CVLC..." << RESET << endl;
        system(command.c_str());
    }
    // Check for MPV
    else if (system("which mpv > /dev/null 2>&1") == 0) {
        command = "mpv " + fullFile;
        cout << BRIGHT_GREEN << "▶ Playing with MPV..." << RESET << endl;
        system(command.c_str());
    }
    // No supported player
    else {
        cout << BRIGHT_RED << "❌ No supported video player found (vlc/cvlc/mpv)." << RESET << endl;
        cout << BRIGHT_YELLOW << "💡 Please install one to play the video." << RESET << endl;
    }

    return 0;
}

