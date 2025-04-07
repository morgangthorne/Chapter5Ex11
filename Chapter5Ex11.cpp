/*
Filename: Chapter5Ex11.cpp
Programmer: Morgan Thorne
Date: March 2025
Requirements:
Write program that can be used as a math tutor
1: Program should display two random numbers to be added
2: Program should pause while students works on problem
3: When student is ready they can press a key and the program will show correct answer
Use at least 3 modules
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

void DisplayMessage(string text);
bool GetRepeatInfo();
int RandomNumberGenerator(int x, int y);
void DisplayEquation();



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

//Displays equation for user, user has to press enter to get answer
void DisplayEquation(int Rx, int Ry, int result) {
    cout << setw(9) << right << Rx << endl;
    cout << "+" << setw(8) << right << Ry << endl;
    cout << "_________";
    cin.ignore();
    cin.get();
    cout << setw(9) << right << result << endl;
}

//Main function, displays welcome message, while statement allows equation to be displayed and then repeated or ended
int main()
{
    DisplayMessage("\t Welcome to Math Tutor V1.0\nPress Enter to check sum after working the problem ");
    char repeat = 'Y';
    int Xvariable;
    int Yvariable;
    while (repeat) {
        Xvariable = RandomNumberGenerator(0, 100);
        Yvariable = RandomNumberGenerator(0, 100);

        DisplayEquation(Xvariable, Yvariable, Xvariable + Yvariable);

        repeat = GetRepeatInfo();
    }
}