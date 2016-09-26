//A simple Multiplication problem generator that seeks the correct answer of two integers
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
int difficulty = 0;
int type = 0;

//Decides what kind of operation the user wants
while (true)
{
    cout << "Enter the number (1) for addtion, (2) for subtraction, (3) for multiplication" <<endl;
    if ((cin >> type) && (type >= 1) && (type <= 3)) break;
    cout << "error, Please enter a number from 1-3 \n";
    cin.clear();
}

//Gets Difficulty, must be an integer from 1-4
    while (true)
{
    cout << "How many digits will be in each integer (1-4)" << endl;
    if ((cin >> difficulty) && (difficulty >= 1) && (difficulty <= 4)) break;
    cout << "error, try again\n";
    cin.clear();
}

//initialzation of variables for when the quiz starts
int correct = 0;
int total = 0;
int answer = 0;
int num1, num2;
string blank;
srand(time(NULL));

//Quiz starts here
cout << "type end to stop the program and receive your score" << endl;
while (true)
{
    //generate random numbers based on selected difficulty
    num1 = rand() % (int)pow(10.0,(double)difficulty) + 1;
    num2 = rand() % (int)pow(10.0,(double)difficulty) + 1;

    if (type == 1)
    cout << "What is " << num1 << "+" << num2 << endl;
    else if (type == 2)
    cout << "What is " << num1 << "-" << num2 << endl;
    else if (type == 3)
    cout << "What is " << num1 << "x" << num2 << endl;

    //considers what the user answered
    if ((cin >> blank) && (blank == "end"))break;
    else
    {
    answer = atoi(blank.c_str());
    if (type == 3)
    {

        if ((answer == num1 + num2))
        {
        cout << "Correct" << endl;
        correct += 1;
        }
        else
         cout << "Incorrect. Answer was: " << num1 + num2 <<endl;
    }

    else if (type == 2)
    {
        if ((answer == num1 - num2))
        {
        cout << "Correct" << endl;
        correct += 1;
        }
        else
        cout << "Incorrect. Answer was: " << num1 - num2 <<endl;
    }

    else if (type == 3)
    {

        if ((answer == num1 * num2))
        {
        cout << "Correct" << endl;
        correct += 1;
        }
        else
        cout << "Incorrect. Answer was: " << num1 * num2 <<endl;
    }

    }

    total += 1;
    cin.clear();

}
cout << "You got " << (double)correct/(double)total * 100.0 << "% correct" << endl;
}
