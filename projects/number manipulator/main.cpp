// Roster Number : A04861544
//
// Author: Kody Gentry
// Due Date: such as 09/09/2020
// Assignment Number: 1
// Fall - 2020 - CS 3358 - .007
// IinputArrayuctor: Husain Gholoom
//
// A number manipulator

#include <iostream>
#include <string>
using namespace std;

class numberManipulation{
private:
    int input; // user input 0 < x < 200
public:
    void setInput(int value){
        input = value;
        /*
         * sets value to private member from user input
         */
    }
    void displayMenu(){
        cout << "\nWelcome to My App.\n"
             << "This App accepts an integer from the keyboard.\n"
             << "The App Calculates and Displays the Following :\n\n"
             << "1. Assuming that The integer represents a $$ amount, then\n"
             << "   the number of quarters, dimes, nickels, and pennies\n"
             << "   will be calculated and displayed\n\n"
             << "2. Assuming that the integer represents person’s Age in years then,\n"
             << "   Number of months, days, hours, minutes, and seconds for the person\n"
             << "   will be calculated and displayed\n\n"
             << "3. The numbers will be separated into its individual digits.\n"
             << "   Then each digit of the integer will be displayed in English.\n\n"
             << "4. Indicate whether or not the integer is an arm strong number.\n\n"
             << "5. Indicate whether or not the integer is prime. Then,\n"
             << "   All the prime numbers between 1 and that number will also be displayed.\n\n"
             << "6. The hailstone sequence starting at n will be calculated and displayed\n\n";
        /*
         * displays one-time menu
         */
    }
    void disperseDollars(){
        cout << "\nCurrency Calculation\n"
             << "$" << input << " "
             << "is equivalent to:\n"
             << (input/25.0)*100.0 << "\tquarter/s\n"
             << (input/10.0)*100.0 << "\tdime/s\n"
             << (input/5.0)*100.0 << "\tnickel/s\n"
             << (input/1.0)*100.0 << "\tcent/s\n";
        /*
         * Assuming that the number represent dollar amount , The function computes the
         * number of quarters, dims, nickels, and pennies to be displayed
         */
    }
    void disperseYears(){

        cout << "\nAge Calculation\n"
             << "Assuming that you are " << input
             << " years old, then:\n"
                "You are " << input*12 << " months old\n"
                "You are " << input*365 << " days old\n"
                "You are approximately " << input*365*24 << " hours old\n"
                "You are approximately " << input*365*24*60 << " minutes old\n"
                "You are approximately " << input*365*24*60*60 << " seconds old\n";
        /*
         * Assuming that the number represents a person’s age. The function then calculates
         * and displays statistics about the age. Assuming that there are 365 days in a year , The
         * proram displays the following information : -
         * Number of year , Number of months , numbers of days , number of hours , number
         * of minutes , and number of seconds for the person.
         */
    }
    void separateAndConvertToEnglish(){
        cout << "\nSeparating digits for the integer " << 12 << endl;

        int inputArray[3];
        int tempInput = input;

        for (int i = 2; i >= 0; i--) {     // initializing array
            inputArray[i] = tempInput % 10;   // modular arithmetic
            tempInput /= 10;
        }

        if (inputArray[0] != 0){           // check if first digit = 0
            for (int i = 0; i < 3; i++){  // do not want output to begin with zero
                cout << inputArray[i] << " ";
            }
        } else {                          // if first digit = 0
            if (inputArray[1] != 0){     // check if second digit = 0 (if first = 0)
                for (int i = 1; i < 3; i++){
                    cout << inputArray[i] << " ";
                }
            } else {
                cout << inputArray[2];
            }
        }
        cout << endl;

        string digits[10] = {"zero","one","two","three","four",
                             "five","six","seven","eight","nine"}; // array of possible outputs
        string outputArray[3];                                    // stores output strings

        for (int j = 0; j < 3; j++) {       // iterate over each char from input
            for (int i = 0; i < 10; i++) { // iterate from 0 - 10 to find a match
                if (inputArray[j] == i) {
                    outputArray[j] = digits[i];
                }
            }
        }

        // checks if the input begins with zero, wont output the zero
        if (inputArray[0] != 0){            // check if first digit = 0
            for (int i = 0; i < 3; i++){   // do not want output to begin with zero
                cout << outputArray[i] << " ";
            }
        } else {
            if (inputArray[1] != 0){      // check if second digit = 0 (if first = 0)
                for (int i = 1; i < 3; i++){
                    cout << outputArray[i] << " ";
                }
            } else {
                cout << outputArray[2]; // output last digit
            }
        }

//        A Function that separate the numbers into its individual digits and prints on the
//        screen the digits separated from one another by three spaces each. The function then
//        displays each digit of the integer in English.

    }
    bool checkArmstrong(){
        int inputArray[3];
        int tempInput = input;
        cout << endl;
        for (int i = 2; i >= 0; i--) {     // initializing array
            inputArray[i] = tempInput % 10;   // modular arithmetic
            tempInput /= 10;
        }

        // calculate armstrong (a^3+b^3+c^3)
        int armstrong = inputArray[0]*inputArray[0]*inputArray[0] +
                        inputArray[1]*inputArray[1]*inputArray[1] +
                        inputArray[2]*inputArray[2]*inputArray[2];

        return armstrong == input;

//        A positive integer is called an Armstrong number if the sum of cubes of individual
//        digit is equal to that number itself. For example:
//        153 = 1*1*1 + 5*5*5 + 3*3*3 // 153 is an Armstrong number.
//        12 is not equal to 1*1*1+2*2*2 // 12 is not an Armstrong number.
//        returns true if armstrong
    }
    bool checkPrime(){
        int i, middle = 0, flag = 0;
        middle =input/2;

        for(i = 2; i <= middle; i++){
            if(input % i == 0){
                return false;
            } else
                return true;
        }
//        Function that indicate whether or not the integer that the digit is a prime number. The
//        function also display all the prime numbers between 1 and that number.
    }
    int displayHailstoneSequence(int input){
        static int sequence;
        cout << input << " ";

        if (input == 1 && sequence == 0) {
            return sequence;
        }
        else if (input == 1 && sequence != 0) {
            sequence++;
            return sequence;
        }
        else if (input % 2 == 0) {
            sequence++;
            displayHailstoneSequence(input / 2);
        }
        else if (input % 2 != 0) {
            sequence++;
            displayHailstoneSequence(3 * input + 1);
        }
        //    A function to display all hailstone sequence. Given any positive integer n, the
//    hailstone sequence starting at n is obtained as follows. You write a sequence of
//    numbers, one after another. Start by writing n. If n is even, then the next number is
//    n/2. If n is odd, then the next number is 3n + 1. Continue in this way until you write
//    the number 1.
    }
};


int main() {
    numberManipulation manipulate; // declare object of class numberManipulation

    manipulate.displayMenu();
    /// main loop
    bool running = true;
    while (running) {
        /// get user input
        cout << "\nEnter a Positive integer Number > 0 and < 200 ---> ";
        int input;
        cin >> input;
        if (input > 0 && input < 200) {
            manipulate.setInput(input); // set private field to user input

            /// process class member functions
            manipulate.disperseDollars();

            manipulate.disperseYears();

            manipulate.separateAndConvertToEnglish();

            if(manipulate.checkArmstrong()){
                cout << endl << input << " is an Armstrong Number\n";
            } else
                cout << endl << input << " is NOT an Armstrong Number\n";

            // all possible primes in bounds
            int primes[47] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                            47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                            103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
                            157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

            if(manipulate.checkPrime()){
                cout << endl << input << " is a prime number\n";
            } else {
                cout << endl << input << " is NOT a prime number\n"
                     << "All prime numbers between 1 and 12 are\n";
                for(int i = 0; i < 47; i++){
                    if (primes[i] < input){
                        cout << primes[i] << "\tnumber is prime" << endl;
                    } else
                        break;
                }
            }

            cout << "\nThe sequence of hailstone starting at " << input << " is\n";
            manipulate.displayHailstoneSequence(input);
            cout << endl;

            // check if user wants new input
            char newNumberChoice; // user choice to try a new number
            cout << "\nTry another number?\n"
                 << "(Y/N)";
            cin >> newNumberChoice;

            // check user input error
            if (newNumberChoice == 'Y' || newNumberChoice == 'y') {
                running = true; // run program again with new number
            } else if (newNumberChoice == 'N' || newNumberChoice == 'n') {
                cout << "09/09/2020 Implemented by Kody Gentry"
                     << "\n...program terminated...\n";
                running = false; // terminate program
            } else
                cout << "Error *** Invalid choice - Must be Y/N\n"; // input error / character error
        } else {
            cout << "Error *** Number must be > 0 and < 200 \n"; // input bounds error / character error
        }
    }
    return 0;
}
