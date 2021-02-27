// Project 1 Chada Tech Clocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Rudy Flores
// 01/18/2021
//

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void ClearScreen();
void DisplayTime(int sHr, int sMin, int sSec, int dHr, string abrivation);
void DisplayOptions();
int GetUserInput();
void GetNewTime(int operation, int& hour, int& min, int& sec, int& dHour, string& abri);
void GetCurrentTime(int& hour, int& min, int& sec, int& dHour, string& abri);

int main()
{
    // decare two set of variables for Hour, Min and Sec. One will be the stardard and the other will be non-standard.
    // Stardard Time variables
    int standardHr;
    int standardMin;
    int standardSec;

    int domesticHr;
    string domesticAbrivation; // used for PM or AM

    // loop variable
    bool loop = true;

    // User input variable to determine how program continues
    int userInput;

    GetCurrentTime(standardHr, standardMin, standardSec, domesticHr, domesticAbrivation);

    while (loop) {
        try {
            DisplayTime(standardHr, standardMin, standardSec, domesticHr, domesticAbrivation);
            DisplayOptions();

            userInput = GetUserInput();

            if (userInput == 4){ //Exits program if user selected 4.
                break;
            }
            else {
                GetNewTime(userInput, standardHr, standardMin, standardSec, domesticHr, domesticAbrivation);
                ClearScreen();

            }
        }
        catch (runtime_error& excpt) {
            //Prints error message for entering incorrect value
            ClearScreen();
            cout << excpt.what() << endl;
        }
    }
    cout << endl << "Good Bye!" << endl;
}

void ClearScreen() {
    system("cls");
}

void DisplayTime(int sHr, int min, int sec, int dHr, string abrivation) {
    //Creates  table and prints current time.
    cout << "\t*************************\t*************************" << endl;
    cout << "\t*     12-Hour Clock     *\t*     24-Hour Clock     *" << endl;
    cout << "\t*      " << setfill('0') << setw(2) << dHr << ":" << setw(2) << min << ":" << setw(2) << sec << " " << abrivation;
    cout << "\t*\t*";
    cout << "\t " << setfill('0') << setw(2) << sHr << ":" << setw(2) << min << ":" << setw(2) << sec << "\t*" << endl;
    cout << "\t*************************\t*************************" << endl;
}

void DisplayOptions() {
    // prints selection menu
    cout << "\t\t\t*************************" << endl;
    cout << "\t\t\t*1 - Add One Hour       *" << endl;
    cout << "\t\t\t*2 - Add One Minute     *" << endl;
    cout << "\t\t\t*3 - Add One Second     *" << endl;
    cout << "\t\t\t*4 - Exit Program       *" << endl;
    cout << "\t\t\t*************************" << endl;
}

int GetUserInput() {
    // function gets user input and returns it to main function. Function also
    // determines if user input a non acceptable value.
    int userInput;

    cout << "Enter an option: ";
    cin >> userInput;

    if ((userInput < 1) || (userInput > 4)) {
        throw runtime_error("Invalid option selected. Please try again.");
    }
    else {
        return userInput;
    }
}

void GetNewTime(int operation, int& hour, int& min, int& sec, int& dHour, string& abri) {
    // Adds 1 Hour
    if (operation == 1) {
        hour += 1;
    }
    // Adds 1 Min
    else if (operation == 2) {
        min += 1;
    }
    // Adds 1 Sec
    else if (operation == 3) {
        sec += 1;
    }

    //checks to see if any variable is over its limit and add 1 to the next variable and reset itself back to 0
    if (sec >= 60) {
        min += 1;
        sec = sec - 60;
    }
    if (min >= 60) {
        hour += 1;
        min = min - 60;
    }
    if (hour >= 24) {
        hour = hour - 24;
    }
    
    dHour = hour;

    // if hour is equal to 0 domestic hour will be equal 1 and if hour > 12 domestic hour will be hour minus 12;
    if (hour == 0) {
        dHour = 12;
    }
    if (hour > 12) {
        dHour = hour - 12;
    }

    //determine the value for abbrivation if hour is between 0 and 11 then it will equal AM otherwise PM
    if (hour < 12) {
        abri = "AM";
    }
    else{
        abri = "PM";
    }

}

void GetCurrentTime(int& hour, int& min, int& sec, int& dHour, string& abri) {


    hour = 15;
    min = 20;
    sec = 45;

    dHour = hour;
    // if hour is equal to 0 domestic hour will be equal 1 and if hour > 12 domestic hour will be hour minus 12;
    if (hour == 0) {
        dHour = 12;
    }
    if (hour > 12) {
        dHour = hour - 12;
    }

    //determine the value for abbrivation if hour is between 0 and 11 then it will equal AM otherwise PM
    if (hour < 12) {
        abri = "AM";
    }
    else {
        abri = "PM";
    }
}