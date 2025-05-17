# OS-Simulator-
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MAANZA OS - README</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0 auto;
            max-width: 800px;
            padding: 20px;
            background-color: #f4f4f4;
        }
        h1, h2, h3 {
            color: #1a73e8;
        }
        pre, code {
            background-color: #e8ecef;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
        ul {
            list-style-type: disc;
            margin-left: 20px;
        }
        a {
            color: #1a73e8;
            text-decoration: none;
        }
        a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <h1>MAANZA OS</h1>
    <p><strong>MAANZA OS</strong> is a terminal-based application suite written in C++ that simulates a simple operating system interface. It provides a menu-driven system to launch various utilities and games, designed to run on Ubuntu. The project features a colorful, user-friendly interface using ANSI color codes and includes robust input validation and error handling.</p>

    <h2>Features</h2>
    <ul>
        <li><strong>Main Menu</strong>: A central interface (<code>main.cpp</code>) to launch all programs in separate terminal windows.</li>
        <li><strong>Login Portal</strong>: A secure login with username, password, and CAPTCHA (<code>intro.cpp</code>).</li>
        <li><strong>Utilities</strong>:
            <ul>
                <li><strong>Calculator</strong>: Perform arithmetic operations (addition, subtraction, multiplication, division, exponentiation, modulus).</li>
                <li><strong>Calendar</strong>: Display a yearly calendar with leap year support.</li>
                <li><strong>Clock</strong>: Show real-time system time, updating every second.</li>
                <li><strong>File Operations</strong>: Copy, cut, delete files, and display file properties (size, permissions, timestamps).</li>
                <li><strong>Text Editor</strong>: Create and edit text files with a simple interface.</li>
            </ul>
        </li>
        <li><strong>Games</strong>:
            <ul>
                <li><strong>Rock Paper Scissors</strong>: Play against the computer with score tracking.</li>
                <li><strong>Number Guessing</strong>: Guess a number between 1 and 100 with hints.</li>
                <li><strong>Hangman</strong>: Guess a secret word with a visual hangman figure.</li>
            </ul>
        </li>
        <li><strong>Media Playback</strong>: Play MP3 audio and MP4 video files using VLC, CVLC, or MPV.</li>
        <li><strong>Resource Monitoring</strong>: Track running processes and estimate RAM/storage usage.</li>
    </ul>

    <h2>Prerequisites</h2>
    <p>Ensure the following are installed on your Ubuntu system:</p>
    <ul>
        <li><strong>G++ Compiler</strong>: For compiling C++ code.</li>
        <li><strong>gnome-terminal</strong>: For launching programs in new terminal windows.</li>
        <li><strong>figlet</strong> and <strong>lolcat</strong>: For the welcome banner in <code>main.cpp</code>.</li>
        <li><strong>vlc</strong>, <strong>cvlc</strong>, <strong>mpg123</strong>, or <strong>mpv</strong>: For audio/video playback.</li>
    </ul>
    <p>Install dependencies using:</p>
    <pre><code>sudo apt update
sudo apt install g++ gnome-terminal figlet lolcat vlc mpg123 mpv
</code></pre>

    <h2>Installation</h2>
    <ol>
        <li>Clone the repository:
            <pre><code>git clone https://github.com/yourusername/maanza-os.git
cd maanza-os
</code></pre>
        </li>
        <li>Compile all C++ files:
            <pre><code>g++ -o calculator calculator.cpp -lm
g++ -o calender calender.cpp
g++ -o clock clock.cpp -pthread
g++ -o copyFile copyFile.cpp
g++ -o cutFile cutFile.cpp
g++ -o deleteFile deleteFile.cpp
g++ -o RockPaperScissors RockPaperScissors.cpp
g++ -o numberGuess numberGuess.cpp
g++ -o song song.cpp
g++ -o video video.cpp
g++ -o notepad notepad.cpp
g++ -o main main.cpp -pthread
g++ -o intro intro.cpp
g++ -o Fileproperties Fileproperties.cpp
g++ -o Hangman Hangman.cpp
</code></pre>
        </li>
        <li>Ensure all compiled executables are in the same directory as <code>main.cpp</code>.</li>
    </ol>

    <h2>Usage</h2>
    <ol>
        <li>Run the main program:
            <pre><code>./main
</code></pre>
        </li>
        <li>Enter RAM and storage capacities (in GB) when prompted.</li>
        <li>Log in via the <code>intro</code> program:
            <ul>
                <li>Username: <code>user</code></li>
                <li>Password: <code>pass</code></li>
                <li>Enter the displayed CAPTCHA number.</li>
            </ul>
        </li>
        <li>Select an option from the menu (1-16):
            <ul>
                <li>1-14: Launch utilities or games.</li>
                <li>15: Terminate a running process by PID.</li>
                <li>16: Display resource usage.</li>
                <li>-1: Exit the program.</li>
            </ul>
        </li>
    </ol>

    <h2>File Descriptions</h2>
    <ul>
        <li><code>main.cpp</code>: Main menu and launcher for all programs.</li>
        <li><code>intro.cpp</code>: Login portal with CAPTCHA verification.</li>
        <li><code>calculator.cpp</code>: Basic arithmetic calculator.</li>
        <li><code>calender.cpp</code>: Yearly calendar display.</li>
        <li><code>clock.cpp</code>: Real-time system clock.</li>
        <li><code>copyFile.cpp</code>: Copies file contents to a new file.</li>
        <li><code>cutFile.cpp</code>: Moves file contents and deletes the source.</li>
        <li><code>deleteFile.cpp</code>: Deletes a specified file.</li>
        <li><code>Fileproperties.cpp</code>: Displays file metadata.</li>
        <li><code>notepad.cpp</code>: Text editor for creating/editing files.</li>
        <li><code>song.cpp</code>: Plays MP3 audio files.</li>
        <li><code>video.cpp</code>: Plays MP4 video files.</li>
        <li><code>RockPaperScissors.cpp</code>: Rock, Paper, Scissors game.</li>
        <li><code>numberGuess.cpp</code>: Number guessing game (1-100).</li>
        <li><code>Hangman.cpp</code>: Hangman word guessing game.</li>
        <li><code>newfile.txt</code>, <code>newfiletest.txt</code>: Sample text files for testing.</li>
    </ul>

    <h2>Notes</h2>
    <ul>
        <li>Ensure all executables are in the same directory as <code>main</code>.</li>
        <li>Audio/video playback requires MP3/MP4 files in the same directory.</li>
        <li>The calendar file is named <code>calender.cpp</code> (typo); consider renaming to <code>calendar.cpp</code>.</li>
        <li>Resource usage calculations are estimates and may not reflect actual system usage.</li>
    </ul>

    <h2>Contributing</h2>
    <p>Contributions are welcome! Please submit a pull request or open an issue on the <a href="https://github.com/yourusername/maanza-os">GitHub repository</a>.</p>

    <h2>Credits</h2>
    <p>Developed by Maidah Nasir (23f-0764) and Anza Naseer (23f-0631) as part of an Operating Systems Lab Project at FAST-NU.</p>

    <h2>License</h2>
    <p>This project is licensed under the MIT License.</p>
</body>
</html>
