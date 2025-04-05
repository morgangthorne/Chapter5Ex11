/*
Filename: Chapter5Ex11.cpp
Programmer: Morgan Thorne
Date: April 2025
Requirements: 
Write a program that can be used as a math tutor for a student, program should display two random numbers
The program should wait for the student to answer, if correct show congratulations message
If wrong show incorrect message and then the answer
All user input should be validated.
This program should have at least 3 modules ( including the main module) and should be repeatable.
Each module should have a brief comment on what the module is intended to do.
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

void DisplayMessage(string text);
bool GetRepeatInfo();
int RandomNumberGenerator(int x, int y);




//Function for random number generator. Gives X and Y variable random value
int RandomNumberGenerator(int x, int y) {
    random_device R;
    uniform_int_distribution<int> randomInt(x, y);

    return randomInt(R);

}

//Function displays Welcome message
void DisplayMessage(string text) {
    cout << text << endl;

}

//Allows user to choose whether they want another equation to solve or to end program
bool GetRepeatInfo() {
    char choice;
    cout << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

//Displays equation then prompts user to input their answer, and return boolean indicationg whether wrong or correct
bool PromptUserAnswerValidate(int Rx, int Ry, int result) {
    int answer;
    cout << setw(9) << right << Rx << endl;
    cout << "+" << setw(8) << right << Ry << endl;
    cout << "_________\n";
    cin >> answer;
    if (answer == result) {
        return true;
    }
    else
        return false;
}

//Main function, displays welcome message, while statement allows equation to be displayed and then repeated or ended
int main()
{
    DisplayMessage("\t Welcome to Math Tutor V1.0\nEnter in your answer to check whether its right or wrong ");
    char repeat = 'Y';
    int Xvariable;
    int Yvariable;
    int answer;
    int result;
    bool isanswercorrect;
    while (repeat) {
        Xvariable = RandomNumberGenerator(0, 100);
        Yvariable = RandomNumberGenerator(0, 100);

        //Bool isanswercorrect will return as true or false if user answer is correct or incorrect
        isanswercorrect = PromptUserAnswerValidate(Xvariable, Yvariable, result = Xvariable + Yvariable);


        if (isanswercorrect) {
            cout << "Correct!\n";
        }
        else {
            cout << "Incorrect!\nThe sum of " << Xvariable << " + " << Yvariable << " = " << result << endl;
        }


        repeat = GetRepeatInfo();

    }

}