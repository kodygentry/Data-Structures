// Author: Kody Gentry
//
// Due Date: 11/20/2020
//
// Programming Assignment Number 7 - Optional
//
// Fall 2020 - CS3358 - 7
//
// Intstructor: Husain Gholoom
//
// C++ program to implement a hashed array
#include <iostream>
#include <stdlib.h>
using namespace std;

// Hash class prototype
class Hash{
    private:
        int hashPos;
        int aNum = 0, sNum = 0, dNum = 0;
        char array[30];
    public:
        Hash();
        void insert();
        void search();
        int hash(char);
        int reHash(char);
        void Delete();
        void Display();
        void probe(char, int);
        int probeOutput(char);
};
// Hash class field definitions
// constructor to populate array
Hash::Hash(){
    for(int i = 0; i < 30; i++){
        array[i] = '-';
    }
    for(int i = 0; i < 30; i++){
        char cch = 'a' + rand()%26;
        array[i] = cch;
    }
}
// function that stores how many probes happened in a certain function within the class
void Hash::probe(char type, int num){
    switch(type){
        case 'a':
            aNum = num;
            break;
        case 's':
            sNum = num;
            break;
        case 'd':
            dNum = num;
            break;
    }
}
// function that outputs how many probes happened in certain functions within the class
int Hash::probeOutput(char type){
    switch(type){
        case 'a':
            return aNum;
            break;
        case 's':
            return sNum;
            break;
        case 'd':
            return dNum;
            break;
        default:
            break;
    }
}
// function that inserts a char into the array
void Hash::insert(){
    char data;
    int count = 0, num = 0;
    cout << "Enter a char you want to insert: ";
    cin >> data;
    bool invalid = false;
        while(invalid){
            if(data >= 'A' && data <= 'Z'){ 
                invalid = true;
                cout << "\nChar must be lower case...\n";
                cout << "Enter a char you want to insert: ";
                cin >> data;
            }
            else if(data >= 'a' && data <= 'z'){
                invalid = false;
            }
            else{
                invalid = true;
                cout << "\nInvalid Input...\n";
                cout << "Enter a char you want to insert: ";
                cin >> data;
            }
        }
    hashPos = hash(data);
    if(hashPos >= 30){
        hashPos = 0;
    }
    while(array[hashPos] != '-'){
        hashPos = reHash(hashPos);
        count++;
        if(count>=30){
            cout << "Array is full\n";
            break;
        }
    }

    bool collision = false;
    while(collision){
        if(array[hashPos] == '-'){
            array[hashPos] = data;
        } else {
            collision = true;
            hashPos + 1;
            num++;
        }
    }
    probe('a', num);
    cout << "The char " << data << " was inserted in location number " << hashPos << endl;
}
// function that hashes the array given an input
int Hash::hash(char key){
    return key%10;
}
// function that hashes the array after array is adjusted
int Hash::reHash(char key){
    return (key+1)%10;
}
// function that searches the array for a char
void Hash::search(){
    char key;
    int i = 0, num = 0;
    bool isFound = false;
    cout << "Enter a char you want to search: ";
    cin >> key;
    for(i = 0; i < 30; i++){
        if(array[i] == key){
            isFound = true;
            num++;
            break;
        }
    }
    probe('s', num);
    if(isFound){
        cout << "The key is found at index " << i << endl;
    }else{
        cout << "The char " << key << " was not found in the array" << endl;
    }
}
// function that deletes a char from the array
void Hash::Delete(){
    char key;
    int i = 0, num = 0;
    bool isFound = false;
    cout << "Enter a char you want to delete: ";
    cin >> key;
    for(i = 0; i < 30; i++){
        if(array[i] == key){
            isFound = true;
            num++;
            break;
        }
    }
    probe('d', num);
    if(isFound){
        array[i] = '-';
        cout << key << " is deleted from the array" << endl;
    }else{
        cout << key << " not found in the array";
    }
}
// function that displays the hashed array
void Hash::Display(){
    cout << "Displaying the generated array.\n";
    for(int i = 0; i < 15; i++)
        cout << array[i] << "  ";
    cout << endl;
    for(int i = 15; i < 30; i++)
        cout << array[i] << "  ";
}
int main(){
    // go over Hashing notes!
    
    // create char array size 30
    // populate first 27 with chars from a-z (formula)
    // if collision, use linear probing (formula)
    // display intro and array (menu)
    // display num of linear probing, searching and deleting
    Hash h;
    char choice;
    cout <<   "Welcome to my Hashing Program\n"
         <<   "------------------------------\n"
         <<   "A. Creates an char array of size 30. Assigning - to each "
         <<   "location in the array indicating that the array is empty.\n"
         <<   "B. Populates 27 elements of the array with random characters "
         <<   "between a and z inclusive.\n"
         <<   "C. If a collision occurs, linear probing will find the next "
         <<   "available position / location.\n"
         <<   "D. The generated array will be displayed in 2 lines.\n"
         <<   "Each line contains 15 characters separated by 2 spaces.\n\n";
    h.Display();
    cout << endl;
    while(1){
        cout << "\n\nA) Display The Generated Array\nB) Search for a character in the array"
             << "\nC) Insert a New Character in the Array\nD) Delete a Character from the Array"
             << "\nX) End The Program\n";
        cout << "Enter your choice: ";
        cin >> choice;
       
        switch(choice){
            case 'A':
                h.Display();
                break;
            case 'B':
                h.search();
                break;
            case 'C':
                h.insert();
                break;
            case 'D':
                h.Delete();
                break;
            case 'X':
                cout << "\nThe number of linear probes when each number is hashed and "
                     << "collision occurred when adding a character in the array is " 
                     << h.probeOutput('a');
                cout << "\nThe number of linear probes when each number is hashed and "
                     << " collision occurred when searching for a character in the array is "
                     << h.probeOutput('s');
                cout << "\nThe number of linear probes when each number is hashed and collision "
                     << "occurred when deleting a character from the array is "
                     << h.probeOutput('d');
                cout << "\nThis hashing program was implemented by Kody Gentry\n11/30/2020\n";
                exit(0);
            default:
                cout << "\nInvalid option\n";
                break;
        }
 }
    return 0;
}