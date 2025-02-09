#include <iostream>
#include <iomanip>

#define TRUE 1
#define FALSE 0

using namespace std;

int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char *months[] = {
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

// Function to input year
int inputyear(void) {
    int year;
    cout << "Please enter a year (example: 1999): ";
    cin >> year;
    return year;
}

// Function to determine the first day of the year
int determinedaycode(int year) {
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;

    return daycode;
}

// Function to check if a year is a leap year
int determineleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] = 29; // February has 29 days in a leap year
        return TRUE;
    } else {
        days_in_month[1] = 28;
        return FALSE;
    }
}

// Function to print the calendar
void calendar(int year, int daycode) {
    int month, day;

    for (month = 0; month < 12; month++) {
        cout << months[month];
        cout << "\n\nSun Mon Tue Wed Thu Fri Sat\n";

        // Print leading spaces for first row
        for (day = 0; day < daycode; day++) {
            cout << "    ";
        }

        // Print days of the month
        for (day = 1; day <= days_in_month[month]; day++) {
            cout << setw(4) << day;
            if (++daycode > 6) {
                daycode = 0;
                cout << endl;
            }
        }
        cout << endl;
    }
}

// Main function
int main(void) {
    int year, daycode, leapyear;

    year = inputyear();
    daycode = determinedaycode(year);
    leapyear = determineleapyear(year);
    calendar(year, daycode);

    return 0;
}
