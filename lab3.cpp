// AUTHOR:   Ekaterina Kuznetsova
// FILENAME: lab3.cpp
// DATE:     10/16/2022
// PURPOSE:  This program prompts the user to input a filepath that includes
//           a list of text on several lines. The program reads each line,
//           removes spaces and changes uppercase letters to lower, and
//           checks if the remains are a palindrome or not. The program
//           prints the line and states whether it is a palindrome or not.
// INPUT:    User input of filepath, user input on whether the user wants to
//           repeat the program.
// PROCESS:  Program checks if text of each line is palindrome.
// OUTPUT:   Prints each line and whether it is a palindrome or not.

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void welcome();
// Welcome user to program and provide introduction
// IN: none
// MODIFY: none
// OUT: none

void getFilepath(string &filepath);
// Receive and validate input from user for the filepath
// IN: String variable holding filepath name
// MODIFY: none
// OUT:

void assessText(string &filepath);
// Grab text line by line from file and push to validating string, then push
// string to a palindrome checking function
// IN: String variable holding filepath name
// MODIFY: none
// OUT:

string validateString(string line);
// Check if string has spaces or capital characters, omit spaces, swap
// capital characters for lower case characters, push to ss to be new string.
// IN: String variable holding line of text
// MODIFY: none
// OUT: String variable holding filepath name

bool isPalindrome(string line);
// If string length is 0 or 1, return true; if string length is 2, compare
// s(0) character with s(1), if they are equal, return true, otherwise false;
// If string length is greater than 2, compare most outer characters, if they
// are equal, omit these letters when pushing string characters to ss to
// create new string, and call isPalindrome with updated string, otherwise
// return false.
// IN: String variable holding updated line of text
// MODIFY: none
// OUT: True or false based on equality of characters in string

void goodbye();
// Thank the user for using the program.
// IN: none
// MODIFY: none
// OUT: none

int main() {

    //welcome message & welcome function
    welcome();

    //declare string variable to hold user input
    string input;

    //do-while loop to enter files - program will not proceed without files
    do{

        //declare string variable to hold filepath
        string filepath;

        //get filename from user
        getFilepath(filepath);

        //call function to take in content from file and
        assessText(filepath);

        cout << "\nWould you like to enter another filepath? (Y for yes): ";
        cin >> input;

    }while(input == "Y" || input == "y");

    //call goodbye function
    goodbye();

}

void welcome(){

    //initiate the welcome message
    string welcomeMessage = "\nWelcome to Palindrome Check!"
                            "\nThis program will read your file and state\n"
                            "if your text is a palindrome or not.\n";

    //print welcome message
    cout << welcomeMessage;
}

void goodbye(){

    //initiate the welcome message
    string goodbyeMsg = "\nThanks for using Palindrome Check!";

    //print welcome message
    cout << goodbyeMsg;
}

void getFilepath(string &filepath) {

    //prompt user for filepath
    cout << "\nEnter the file with text: ";

    //read in user input
    cin >> filepath;
    cout << endl;

    //open the file - ifstream is a datatype used to read from file
    ifstream inFile;
    inFile.open(filepath);

    //if the file does not open, ask for filepath again and take in filepath
    while (!inFile.is_open()) {

        cout << "File is invalid. Try again: ";
        cin >> filepath;

    }

}

void assessText(string &filepath) {

    //declare string variables to hold a line from file and a section of line
    string line;

    //open the file - ifstream is a datatype used to read from file
    ifstream inFile;
    inFile.open(filepath);

    //loop until the end of the file
    while (getline(inFile, line)) {

        //call validation function to remove invalid characters and return
        //updated string
        string str = validateString(line);

        //print original line
        cout << line;

        //check if the updated string is a palindrome
        if (isPalindrome(str)) {

            //if it is, print it to the screen
            cout << " is a palindrome" << endl;

        } else {

            //if it is not, print it to the screen
            cout << " is not a palindrome" << endl;

        }

    }

}

string validateString(string line){

    //declare char to hold individual letters of string
    char c;
    //get length of the string
    int n = line.length();

    //declare string stream
    stringstream ss;

    //iterate through the string to validate characters
    for (int i = 0; i < n; i++) {

        //assign letter of string to the character
        c = line[i];

        //if the character is not a space, set it to lower case and push to ss
        if (!isspace(c)) {
            c = tolower(c);
            ss << c;
        }

    }

    //return accumulated string of only valid characters
    return ss.str();

}

bool isPalindrome(string newString){

    //get the length of the current string
    int len = newString.length();

    //declare string stream
    stringstream ss;

    //if the string is empty or if it is only one letter
    if (len == 0 || len == 1) {

        //palindrome bc either are reversable
        return true;

    //if the string is 2 letters
    } else if (len == 2){

        //compare the two letters, return true if they are equal to each other
        if (newString.at(0) == newString.at(1)){
            return true;

        //if they are not equal, return false
        } else {
            return false;
        }

    //if the length is more than 2
    } else {

        //compare the first and the last letters in the string, if they are
        // equal:
        if (newString.at(0) == newString.at(len-1)) {

                //only keep the middle letters (outside letters removed)
                for (int i = 1; i < len-1; i++) {

                    //push middle letters into ss
                    ss << newString.at(i);
                }

                //update the string variable
                ss >> newString;

                //clear ss contents
                ss.str("");

                //call the function again with the updated string variable
                return isPalindrome(newString);

        //if the first and last letters of the string are not equal, it is not a
        // palindrome, therefore return false
        } else {

            return false;

        }

    }

}
