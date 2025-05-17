#**Operating System Simulator**#
# 🚀 **MAANZA OS: A Terminal-Powered Mini OS**

**MAANZA OS** is a vibrant, C++-based terminal application suite that emulates a lightweight operating system. Built for Ubuntu, it offers a colorful interface with a central menu to launch utilities, games, and media players, complete with resource tracking and a secure login system. Perfect for exploring OS concepts in a fun, interactive way!


## 🌟 **What Makes MAANZA Special?**

* **Interactive Hub**: A dynamic menu launches **13 unique programs** in separate `gnome-terminal` windows.
* **Secure Access**: Login with username, password, and CAPTCHA verification.
* **Utility Suite**: Tools for calculations, file management, and text editing.
* **Gaming Corner**: Enjoy Rock Paper Scissors, Number Guessing, and Hangman.
* **Media Playback**: Play MP3 audio and MP4 videos with ease.
* **Resource Insights**: Monitor running processes and estimate system usage.

---

## 🛠️ **System Requirements**

* **OS**: Ubuntu (or any POSIX-compliant Linux system)
* **Tools**: `g++`, `gnome-terminal`, `figlet`, `lolcat`, `vlc`, `mpg123`, `mpv`
* **Environment**: Standard C++ and POSIX libraries

---

## 📦 **Setup Guide**


### ✅ **Grab the Code:**

```bash
git clone https://github.com/Maidah609/OS-Simulator-.git
cd OS-Simulator-/OS_Project
```

### ✅ **Install Tools:**

```bash
sudo apt update
sudo apt install g++ gnome-terminal figlet lolcat vlc mpg123 mpv
```

### ✅ **Compile Programs:**

```bash
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
```

---

## 🎮 **How to Dive In**

### 🚀 **Launch MAANZA:**

```bash
./main
```

### 🖥️ **Set System Specs:**

Enter **RAM** and **storage** (in GB) when prompted.

### 🔐 **Log In Securely:**

* **Username**: `user`
* **Password**: `pass`
* Enter the displayed **CAPTCHA** number.

### 📋 **Explore the Menu:**

* `1-14`: Run utilities (e.g., Calculator, Notepad) or games (e.g., Hangman).
* `15`: Terminate a running process by PID.
* `16`: Check resource usage (RAM, storage, processes).
* `-1`: Exit MAANZA OS.

> Programs launch in new `gnome-terminal` windows for a seamless experience.

---

## 📂 **Inside MAANZA OS**

| File                                                      | Description                                                                         |
| --------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| `main.cpp`                                                | The heart of MAANZA, managing the menu, launching programs, and tracking resources. |
| `intro.cpp`                                               | Secure login with CAPTCHA for user authentication.                                  |
| `calculator.cpp`                                          | Performs arithmetic operations (add, subtract, multiply, divide, etc.).             |
| `calender.cpp`                                            | Displays a yearly calendar with leap year support.                                  |
| `clock.cpp`                                               | Shows a real-time system clock, updating every second.                              |
| `copyFile.cpp`, `cutFile.cpp`, `deleteFile.cpp`           | File operations for copying, moving, and deleting.                                  |
| `Fileproperties.cpp`                                      | Shows file details like size, permissions, and timestamps.                          |
| `notepad.cpp`                                             | Simple text editor for creating and editing files.                                  |
| `song.cpp`, `video.cpp`                                   | Play MP3 audio and MP4 videos using VLC, mpg123, or MPV.                            |
| `RockPaperScissors.cpp`, `numberGuess.cpp`, `Hangman.cpp` | Fun games with colorful interfaces.                                                 |
| `newfile.txt`, `newfiletest.txt`                          | Sample text files for testing file operations.                                      |

---

## 🔍 **Key Mechanisms**

* **Login System**: Uses `srand` for random CAPTCHA generation (`intro.cpp`).
* **Calculator**: Validates inputs and handles errors like division by zero.
* **Calendar**: Implements Zeller’s Congruence for accurate day calculations.
* **File Operations**: Robust file handling with error checks for accessibility.
* **Games**: Feature input validation and engaging ASCII/emoji visuals.
* **Resource Tracking**: Scans `/proc` to monitor processes and estimate usage.

---

## ⚠️ **Quick Tips**

* Keep all **executables** in the same directory as `main`.
* Place **MP3/MP4 files** in the directory for `song` and `video` to work.
* Note: `calender.cpp` is misspelled; consider renaming to `calendar.cpp`.
* Resource usage is estimated (0.5 GB RAM, 0.1 GB storage per process).

---

## 🙌 **Credits**

Crafted by **Maidah Nasir** and **Anza Naseer**
for the **Operating Systems Lab Project** at **FAST-NU**.
