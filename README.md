🎓 MAANZA OS
MAANZA OS is a terminal-based C++ application suite simulating a simple operating system interface. It offers a menu-driven launcher for utilities and games, with a colorful ANSI-based UI, designed for Ubuntu.

📁 Features
Login portal with CAPTCHA verification
Utilities: Calculator, Calendar, Clock, File Copy/Cut/Delete, File Properties, Text Editor
Games: Rock Paper Scissors, Number Guessing, Hangman
Media Playback: MP3 audio and MP4 video
Resource Monitoring: Track processes and estimate RAM/storage usage
🗂 File Structure
main.cpp: Main menu and program launcher
intro.cpp: Login with username ("user"), password ("pass"), and CAPTCHA
calculator.cpp: Arithmetic operations
calender.cpp: Yearly calendar display
clock.cpp: Real-time clock
copyFile.cpp, cutFile.cpp, deleteFile.cpp: File operations
Fileproperties.cpp: File metadata display
notepad.cpp: Text file creation/editing
song.cpp, video.cpp: Audio/video playback
RockPaperScissors.cpp, numberGuess.cpp, Hangman.cpp: Games
newfile.txt, newfiletest.txt: Sample text files
🚀 How to Run on Ubuntu
Install dependencies:
sudo apt update
sudo apt install g++ gnome-terminal figlet lolcat vlc mpg123 mpv
Clone the repository:
git clone https://github.com/yourusername/maanza-os.git
cd maanza-os
Compile all programs:
g++ -o calculator calculator.cpp -lm
g++ -o calender calender.cpp
g++ -o clock clock.cpp -pthread
g++ -o copyFile copyFile.cpp
g++ -o cutFile cutFile.cpp
g++ -o deleteFile deleteFile.cpp
g++ -o Fileproperties Fileproperties.cpp
g++ -o notepad notepad.cpp
g++ -o song song.cpp
g++ -o video video.cpp
g++ -o RockPaperScissors RockPaperScissors.cpp
g++ -o numberGuess numberGuess.cpp
g++ -o Hangman Hangman.cpp
g++ -o intro intro.cpp
g++ -o main main.cpp -pthread
Run the main program:
./main
Log in with username user, password pass, and enter the CAPTCHA.
Select options (1-14 for programs, 15 for process termination, 16 for resource usage, -1 to exit).
🔐 Usage Notes
Ensure all executables are in the same directory as main.
Place MP3/MP4 files in the directory for song and video.
calender.cpp has a typo; consider renaming to calendar.cpp.
🧠 Key Functions
main.cpp: Launches programs, monitors resources, terminates processes
intro.cpp: Verifies user credentials and CAPTCHA
calculator.cpp: Handles arithmetic with input validation
calender.cpp: Uses Zeller’s Congruence for calendar display
notepad.cpp: Creates/edits text files
Hangman.cpp: Manages game state with ASCII art
🔧 Dependencies
G++ compiler
POSIX libraries (sys/stat.h, dirent.h, etc.)
External tools: gnome-terminal, figlet, lolcat, vlc, mpg123, mpv
📝 Credits
Developed by Maidah Nasir (23f-0764) and Anza Naseer (23f-0631) for the Operating Systems Lab Project at FAST-NU.

📜 License
MIT License
