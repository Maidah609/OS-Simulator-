#include "pthread.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "bits/stdc++.h"
#include "ctime"
#include "cstdlib"

using namespace std;

int dayNumber(int day, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 +
        year / 400 + t[month - 1] + day) % 7;
}

int numberOfDays(int monthNumber, int year)
{
    if (monthNumber == 0) return 31;
    if (monthNumber == 1) return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
    if (monthNumber == 2) return 31;
    if (monthNumber == 3) return 30;
    if (monthNumber == 4) return 31;
    if (monthNumber == 5) return 30;
    if (monthNumber == 6) return 31;
    if (monthNumber == 7) return 31;
    if (monthNumber == 8) return 30;
    if (monthNumber == 9) return 31;
    if (monthNumber == 10) return 30;
    if (monthNumber == 11) return 31;
    return 0;
}

int main()
{
    int year;
    string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", 
                       "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    string brightColors[] = {"\e[1;91m", "\e[1;92m", "\e[1;93m", "\e[1;94m",
                             "\e[1;95m", "\e[1;96m", "\e[1;97m"};

    while (true)
    {
        cout << "\e[1;93mEnter Year: \e[0m";
        cin >> year;
        cout << "\e[1;93m\n\tCalendar for " << year << "\e[0m\n\n";

        int days;
        int current = dayNumber(1, 1, year);

        for (int i = 0; i < 12; i++)
        {
            cout << brightColors[i % 7] << months[i] << "\e[0m" << endl;
            days = numberOfDays(i, year);

            cout << "\e[1;96m  Sun  Mon  Tue  Wed  Thu  Fri  Sat\e[0m\n";
            int k;
            for (k = 0; k < current; k++)
                cout << "    ";

            for (int j = 1; j <= days; j++)
            {
                cout << "\e[1;92m" << setw(4) << j << "\e[0m";
                if (++k > 6)
                {
                    k = 0;
                    cout << "\n";
                }
            }

            if (k)
                cout << "\n";
            current = k;

            cout << "\n\n"; // spacing between months
        }
    }

    return 0;
}

