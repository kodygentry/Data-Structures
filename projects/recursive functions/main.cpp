// Author: Kody Gentry
// Due Date: such as 10/02/2020
// Assignment Number: 5
// Fall - 2020 - CS 3358 - 7
// Instructor: Husain Gholoom
//
// Write a C++ program that Accepts a positive integer ( n ) that is
// greater than 9 from the keyboard. Then run various recursive functions.

#include <iostream>
using namespace std;

void displayMenu();
bool checkIncreasingOrder(int);
int reverseDigits(int);
int sumOfDigits(int);
int sumOfSquares(int);
void displayVertically(int);

int main(){
    displayMenu();                       // display main menu (once per run)
    bool valid = false, running = true; // valid for validation loop, running for main loop
    int choice, input = 0;             // input for menu choice, input for user integer input

    while(running){                   // main loop
        do {
            cout << "\nSelect from the following menu:\n"      // output menu
                    "1. Enter a positive integer > 9.\n"
                    "9. Terminate the program.";
            cin >> choice;                                  // get choice input (1 or 9)
            if (choice == 1) {                             // option 1 - input
                cout << "\nEnter a positive integer > 9:";  // get user integer input
                cin  >> input;
                if(input <= 9){                         // if input invalid, loop menu for new input
                    cout << "\nInvalid Integer - Integer must be > 9.\n";
                    valid = false;
                } else {
                    valid = true;
                }
            } else if (choice == 9) {                   // option 9 - terminate
                cout << "\nImplemented by Kody Gentry - 11/2/2020.\n";
                valid = false;                        // run validation loop again
                running = false;                     // terminate program
                break;
            } else {
                cout << "\nInvalid Option.\n";    // invalid option
                valid = false;
            }
        } while (!valid); // run this loop while input is invalid

        if (valid) {    // if the input is valid, call methods
            // check increasing order
            if (checkIncreasingOrder(input))
                cout << "The digits of " << input << " are in increasing order.\n";
            else
                cout << "The digits of " << input << " are not in increasing order.\n";

            // reverse digits
            cout << "The original digits are " << input << " --- "
                 << "Digits reversed = " << reverseDigits(input) << endl;

            // sum of digits
            cout << "Sum of digits of the number is = " << sumOfDigits(input) << endl;

            // sum of squares
            cout << "Sum of squares from 0 to " << input << " = " << sumOfSquares(input) << endl;

            // display vertically
            cout << input << " Displayed vertically.\n";
            displayVertically(input);

        }
    }

    return 0;
}
/*
    function that displays a one time menu explaining the
    methods of this program
 */
void displayMenu(){
    cout << "*** Welcome to My Program Using Recursions ***\n"
            "The function of this program is to accept from the "
            "keyboard a positive integer that is > 9.\n"
            "The program then does the following:\n"
            "1. Returns true if the digits of that integer n "
            "are in increasing order; otherwise, the function returns false.\n"
            "2. Returns the numbers with the digits reversed.\n"
            "3. Returns the sum of the digits of the integer.\n"
            "4. Returns the sum of squares of the numbers from 0 to the number n.\n"
            "5. Displays the number vertically.\n";
}
/*
    function that checks if the input's digits are in increasing order
    by sorting through each individual digit using recursion
 */
bool checkIncreasingOrder(int input){
    int curr, next, nextCurr; // variables for checking order
    curr = input % 10;
    next = input/10;
    nextCurr = next % 10;
    if(next != 0){
        if(curr >= nextCurr){
            checkIncreasingOrder(next);
        } else return false;
    } else
        return true;
}
/*
    function that reverses the digits of an int input
    by using modulo and recursion
 */
int reverseDigits(int input){
    static int reverseInput = 0, basePosition = 1; // variables for reversing
    if(input > 0){
        reverseDigits(input/10);
        reverseInput += (input%10)*basePosition;
        basePosition *= 10;
    }
    return reverseInput;
}
/*
    function that adds up the digits of an input using recursion and modulo
 */
int sumOfDigits(int input){
    if (input == 0)
        return 0;
    return (input%10 + sumOfDigits(input/10));
}
/*
    function that adds of the squares of each digit of an input from
    0 to n (n being the input)
 */
int sumOfSquares(int input){
    if (input == 1)
        return input;
    else
        return input*input+sumOfSquares(input-1);
}
/*
    function that displays the input digits vertically using recursion
 */
void displayVertically(int input){
    if(input > 0){
        int temp = input % 10; // temp variable for vertical display
        displayVertically(input / 10);
        cout << temp << endl;
    }
}