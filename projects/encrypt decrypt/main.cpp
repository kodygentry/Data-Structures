// Author: Kody Gentry
//
// Due Date : 09/24/2020
// Programming Assignment Number 2
// Fall 2020 - CS 3358 - 7
//
// Instructor: Husain Gholoom
//
//  a C++ program to encrypt / decrypt a message by
// taking each letter in the message (in cryptography, these letters are
// called symbols because they can be letters ( A-Z) , and numbers( 0-9 ) )
// and replacing it with a “shifted” letter.

// comment: I use a stoi() function in the validate() function
//          If you do not compile this program with C++11
//          or newer, it will give an error.
//          (sorry this was the only solution for me)

#include <iostream>
#include <string>
using namespace std;
#include <vector>

// Function prototypes
bool validate(int errorCheck, string input);
vector<char> encrypt(vector<char> messageElement,int key);
vector<char> decrypt(vector<char> cipherElement, int key);

int main()
{
    cout << "\nWelcome to Cryptography\n";

    // create 2d vector array of type char
    vector<vector<char> > matrix;

    //Variables for input store
    bool running = true;
    string message, option; // message = input from user
    int key;               // option = choice of decrypt/encrypt by user
                          // key = how many shifts
    while (running) {
        /// Prompt for option ------------------------------------------------------
        cout << "\nDo you wish to encrypt or decrypt a message or exit?" << endl;;
        cin >> option;

        // validate
        while (!validate(1, option)) {
            cout << "Error!!!Option should be encrypt/decrypt. Please Re-enter ";
            cout << "Do you wish to encrypt or decrypt a message?" << endl;;
            cin >> option;

        }
        cin.ignore();
        if (option == "exit"){
            running = false;
            break;
        }


        /// Prompt for message -----------------------------------------------------
        cout << "Enter your message:" << endl;
        getline(cin, message);

        // populate the message vector element within the 2d vector array
        vector<char> messageElement(message.length());
        // copy string input to char vector
        copy(message.begin(), message.end(), messageElement.begin());


        /// Prompt for key ---------------------------------------------------------
        cout << "Enter the key number (1-26)" << endl;
        cin >> key;

        // validate
        while (!validate(2, to_string(key))) {
            cout << "Error!!!Key must be 1...26 Please Re-enter. ";
            //Prompt for key
            cout << "Enter the key number (1-26)" << endl;
            cin >> key;
        }


        /// Check for encryption or decryption -------------------------------------
        if (option == "encrypt") {
            // assign cipher to vector of matrix element
            vector<char> cipher = encrypt(messageElement, key);
            // output encryption
            cout << "Your translated text is: \n";
            for (int i = 0; i < cipher.size(); i++) // iterate over each char int he returned vector
                cout << cipher.at(i);
        } else if (option == "decrypt") {
            // assign cipher to vector of matrix element
            vector<char> cipher = decrypt(messageElement, key);
            // output decryption
            cout << "Your translated text is: \n";
            for (int i = 0; i < cipher.size(); i++) // iterate over each char int he returned vector
                cout << cipher.at(i);
        } else {
            running = false;
        }
    }
    return 0;
}

bool validate(int errorCheck, string input){
    // two cases (one for option, one for key)
    switch (errorCheck) {
        case 1:
            return !(input != "encrypt" && input != "decrypt" && input != "exit");
        case 2:
            int temp = stoi(input);
            return !(temp < 1 || temp > 26);
    }

    /*
     * A method that validates input from the user
     * with case input parameter and user input parameter
     */
}
vector<char> encrypt(vector<char> messageElement, int key) {
    // Loop to get each character of message
    for (int i = 0; i < messageElement.size(); ++i) {
        char ch = messageElement[i]; // get character
        if (ch != ' ') {            // Check for alphabet
            if (ch >= 'a' && ch <= 'z') {
                //Add with keys
                ch = ch + key;
                //If it not in alphabet then generate start from a
                if (!(ch >= 'a' && ch <= 'z')) {
                    ch = ch - 'z' + 'a' - 1;
                }
                // Change the shifted character
                messageElement[i] = ch;
            }
                // Capital letter checker
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;

                if (!(ch >= 'A' && ch <= 'Z')) {
                    ch = ch - 'Z' + 'A' - 1;
                }

                messageElement[i] = ch; // assign char to vector
            }
        } else {
            // increment if a space character
            i++;
        }
    }
    //Return encrypted vector
    return messageElement;
}
vector<char> decrypt(vector<char> cipherElement, int key) {

    //Loop to get each character of message
    for (int i = 0; i < cipherElement.size(); ++i) {
        char ch = cipherElement[i]; // get character
        if (ch != ' ') {           // Check for alphabet
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                //If it not in alphabet then generate start from a
                if (!(ch >= 'a' && ch <= 'z')) {
                    ch = ch + 'z' - 'a' + 1;
                }

                cipherElement[i] = ch;
            }
                // Capital conversion
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;

                if (!(ch >= 'A' && ch <= 'Z')) {
                    ch = ch + 'Z' - 'A' + 1;
                }

                cipherElement[i] = ch; // assign char to vector
            }
        } else {
            // increment if a space character
            i++;
        }
    }
    // Return decrypted vector
    return cipherElement;
}



