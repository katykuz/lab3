#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void welcome();

void getFilepath(string filepath);

void intakeText(string filepath);

bool isPalindrome(string line);

string validateString(string line);

void goodbye();

int main() {

    //welcome message&welcome function
    welcome();
    string input;

    //do-while loop to enter files - program will not proceed without files
    do{
        string filepath;


        getFilepath(filepath);

        cout << "\nWould you like to enter another filepath? (Y for yes): ";
        cin >> input;

    }while(input == "Y" || input == "y");

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

void getFilepath(string filepath) {

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

    //call function to take in content from file
    intakeText(filepath);

}

void intakeText(string filepath) {

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
