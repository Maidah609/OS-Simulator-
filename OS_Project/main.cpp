#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
#include <limits>

using namespace std;

double ram = 0, storage = 0;
mutex mtx;

void launchProgram(const string& executableName) {
    string command = "gnome-terminal --disable-factory -- ./" + executableName;
    system(command.c_str());
}

struct MenuOption {
    int id;
    string name;
    string executable;
};

vector<MenuOption> menuOptions = {
    {1, "Intro", "intro"},
    {2, "Calculator", "calculator"},
    {3, "Calendar", "calender"},
    {4, "Clock", "clock"},
    {5, "Copy File", "copyFile"},
    {6, "Delete File", "deleteFile"},
    {7, "File Info", "Fileproperties"},
    {8, "Text Editor", "notepad"},
    {9, "Cut File", "cutFile"},
    {10, "Play Song", "song"},
    {11, "Play Video", "video"},
    {12, "Run Hangman Game", "Hangman"},
    {13, "Run Rock Paper Scissors Game", "RockPaperScissors"},
    {14, "Run Number Guessing Game", "numberGuess"}
};

void printHeader(const string& headerText) {
    int length = headerText.length();
    cout << "\n\033[1;93m\t\t\t<" << string(length + 8, '=') << ">\033[0m\n";
    cout << "\033[1;96m\t\t\t=   " << headerText << "   =\033[0m\n";
    cout << "\033[1;93m\t\t\t<" << string(length + 8, '=') << ">\033[0m\n\n";
}

void displayResources() {
    DIR* dir = opendir("/proc");
    if (!dir) {
        cerr << "Failed to open directory /proc.\n";
        return;
    }

    int processCount = 0;
    struct dirent* ent;
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_DIR) continue;
        string pid_str = ent->d_name;
        if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
        pid_t pid = stoi(pid_str);

        char cmdline_path[64];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (!cmdline_file) continue;

        char cmdline[1024];
        size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
        fclose(cmdline_file);

        if (len == 0) continue;
        cmdline[len] = '\0';

        if (strstr(cmdline, "./") == cmdline) {
            processCount++;
        }
    }
    closedir(dir);

    double usedRAM = 0.5 * processCount;
    double usedStorage = 0.10 * processCount;

    cout << "\033[1;93m\n╭─────[ Resource Usage ]─────╮\033[0m\n";
    cout << "\033[1;96mRunning custom processes:\033[0m " << processCount << "\n";
    cout << "\033[1;92mFree RAM (GB):\033[0m " << max(0.0, ram - usedRAM) << "\n";
    cout << "\033[1;94mFree Storage (GB):\033[0m " << max(0.0, storage - usedStorage) << "\n";
}

void terminateProcessMenu() {
    DIR* dir = opendir("/proc");
    if (!dir) {
        cerr << "Failed to open directory /proc.\n";
        return;
    }

    vector<pid_t> pids;
    struct dirent* ent;
    cout << "\n\033[1;91m[Custom Launched Processes]\033[0m\n";
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_DIR) continue;
        string pid_str = ent->d_name;
        if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
        pid_t pid = stoi(pid_str);

        char cmdline_path[64];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (!cmdline_file) continue;

        char cmdline[1024];
        size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
        fclose(cmdline_file);

        if (len == 0) continue;
        cmdline[len] = '\0';

        if (strstr(cmdline, "./") == cmdline) {
            pids.push_back(pid);
            cout << "\033[1;95mPID:\033[0m " << pid << " | \033[1;94mCommand:\033[0m " << cmdline << endl;
        }
    }
    closedir(dir);

    if (pids.empty()) {
        cout << "\033[1;93mNo custom-launched processes found.\033[0m\n";
        return;
    }

    int pid;
    cout << "\033[1;91mEnter the PID to terminate:\033[0m ";
    cin >> pid;
    if (find(pids.begin(), pids.end(), pid) == pids.end()) {
        cout << "\033[1;91mInvalid PID selected.\033[0m\n";
        return;
    }

    if (kill(pid, SIGKILL) == 0) {
        cout << "\033[1;92mProcess with PID " << pid << " terminated successfully.\033[0m\n";
    } else {
        perror("Failed to terminate process");
    }
}

void showMenu() {
    cout << "\033[1;96mChoose an option:\033[0m\n";
    for (const auto& opt : menuOptions) {
        printf("\033[1;94m%02d. \033[1;97m%s\n", opt.id, opt.name.c_str());
    }
    cout << "\033[1;95m15. Kernel Mode (Terminate Specific Process)\033[0m\n";
    cout << "\033[1;93m16. Display Resources\033[0m\n";
    cout << "\033[1;91m-1. Exit\033[0m\n";
}

int main() {
    system("clear");
    cout << "\033[1;92m[✔] Booting up MAANZA OS...\033[0m\n";
    system("sleep 1");
    system("clear");

    cout << "\n           \033[1;95m═══════════════════════\033[0m\n";
    cout << "           \033[1;96m       Welcome to       \033[0m\n";
    cout << "           \033[1;95m═══════════════════════\033[0m\n\n";

    system("figlet -f slant -c MAANZA | lolcat --seed=42");

    cout << "           \033[1;96mOperating system\033[0m\n\n";

    printHeader("MAIN MENU");

    cout << "\033[1;94mEnter RAM (in GB): \033[0m";
    cin >> ram;
    cout << "\033[1;94mEnter Storage (in GB): \033[0m";
    cin >> storage;

    if (ram <= 0 || storage <= 0) {
        cerr << "\033[1;91mInvalid RAM or Storage value. Exiting.\033[0m\n";
        return 1;
    }

    int choice;
    while (true) {
        sleep(1);
        system("clear");
        displayResources();
        showMenu();
        cout << "\n\033[1;92mEnter your choice: \033[0m";
        cin >> choice;

        if (choice == -1) {
            cout << "\033[1;91mExiting program.\033[0m\n";
            break;
        }

        auto it = find_if(menuOptions.begin(), menuOptions.end(), [choice](const MenuOption& opt) {
            return opt.id == choice;
        });

        if (it != menuOptions.end()) {
            launchProgram(it->executable);
        } else if (choice == 15) {
            terminateProcessMenu();
        } else if (choice == 16) {
            displayResources();
            cout << "\n\033[1;97mPress Enter to continue...\033[0m";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        } else {
            cout << "\033[1;91mInvalid choice.\033[0m\n";
            cout << "\n\033[1;97mPress Enter to continue...\033[0m";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }

    return 0;
}

