// Author : Kody Gentry
//
// Due Date : 10/05/2020
// Programming Assignment Number 3
// Fall 2020 - CS 3358 - 7
//
// Instructor: Husain Gholoom.
//
// a date manipulation program

#include <iostream>
using namespace std;

class DateType {
private:
    int month, day, year; // class fields
public:
    void setDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;

        // class member used to initialize class fields
    }
    int getMonth() {
        return month;

        // specifically used for calcNewDate in main to get the true month after adding 25 days
    }
    bool validateLeapYear() {
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        // given a year, check if leap year by checking mod 4 (boolean)
    }
    string displayMonthName() {
        switch (month) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
            default:
                return "Invalid Month number.";
        }

        // member that converts int input to its respective string month and returns it
    }
    int daysInMonth() {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;
        else if (month == 2) { // special february calculation
            if (validateLeapYear())
                return 29;
            else
                return 28;
        } else
            return 30;

        // checks for days in the month using if statements and returns day
    }
    int daysPassed() {
        switch (month) {
            case 1:
                return day;
            case 2:
                return day + 31;
            case 3:
                return day + 59;
            case 4:
                return day + 90;
            case 5:
                return day + 120;
            case 6:
                return day + 151;
            case 7:
                return day + 181;
            case 8:
                return day + 212;
            case 9:
                return day + 243;
            case 10:
                return 273;
            case 11:
                return 304;
            case 12:
                return day + 334;
            default:
                return -1;
        }

        // returns current day + days before current day to equal total passed
        }
    int daysRemaining() {
        if (validateLeapYear())
            return 366-daysPassed();
        else
            return 365-daysPassed();

        // uses daysPassed function to calculate days remaining by subtracting the result from 365/366
    }
    int calcNewDate() {
        int newDay;
        if ((25+day)>daysInMonth()) {
            newDay = (25 + day) - daysInMonth();
            if (month == 12){
                month = 1;
            } else {
                month++;
            }
        } else {
            newDay = 25 + day;
        }

        return newDay;
        // if the sum of 25 and day is greater than the total days in the month,
        // return the sum of those two minus the total days in the month and increment the month once
        // else just return the summation
        // if the month is december, dont increment, reset to 1
    }
};

bool validate(int m, int d, int y){
    if (m < 1 || m > 12) {
        cout << "Error: Month must be between 1 and 12.\n";
        return false;
    }
    else if (d < 1 || d > 31){
        cout << "Error: Day must be between 1 and 31.\n";
        return false;
    }
    else if (y < 1900){
        cout << "Error: Year must be greater than 1900.\n";
        return false;
    }
    else
        return true;

    // validates user input for month, day, and year, returns true/false
}

int main() {
    cout << "Welcome to 'Date Manipulations Program.'\n";

    bool running = false, valid;   // running used for main loop, valid used for input validation
    int month, day, year; // used to get input from user

    do {

        /// get input
        do {
            cout << "\nEnter a date (00/00/0000):";

            // read the month
            cin >> month;
            if (cin.get() != '/') { // make sure there is a slash between MM and YYYY
                cout << "Input Error: expected /\n";
                return -1;
            }
            // read the day
            cin >> day;
            if (cin.get() != '/') { // make sure there is a slash between DD and MM
                cout << "Input Error: expected /\n";
                return -1;
            }
            // read the year
            cin >> year;
            valid = validate(month, day, year);
        } while (!(valid)); // loop while user input invalid
        cout << "----------------------------------------------------\n";


        // create object and set fields
        DateType date;
        date.setDate(month, day, year);

        /// call methods

        // validate leap year
        if (date.validateLeapYear())
            cout << year << " is a leap year.\n";
        else
            cout << year << " is not a leap year.\n";

        // display month name
        cout << date.displayMonthName() << " " << day << ", " << year << endl;

        // display days in month
        cout << month << "/" << day << "/" << year << " has "
             << date.daysInMonth() << " days.\n";

        // display number of days passed in the year
        if (date.validateLeapYear() && month > 2)
            cout << "Number of days passed in the year is " << date.daysPassed() + 1 << " days";
        else
            cout << "Number of days passed in the year is " << date.daysPassed() << " days";

        // display days remaining
        cout << "\nNumber of days remaining in the year " << year << " is "
             << date.daysRemaining() << " days.\n";

        // calc and display new date
        int newDay = date.calcNewDate();
        cout << "After Adding 25 days to the current date, the new date will be: "
             << date.getMonth() << "/" << newDay << "/" << year << endl;




        cout << "----------------------------------------------------";
        // run again?
        char choice; // used for user choice to run again
        bool invalid; // used for input validation
        do {
            cout << "\nWould you like to re-run the program again? (Y/N)";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                running = true;
                invalid = false;
            }
            else if (choice == 'N' || choice == 'n') {
                running = false;
                invalid = false;
                cout << "\nThis program was implemented by Kody Gentry.\nOctober - 2020.\n";
            } else {
                cout << "Invalid choice: choose Y/N or y/n\n";
                invalid = true;
            }
        } while (invalid);
    } while (running);

    return 0;
}
