#include <iostream>
using namespace std;

#include "factory.h"

int main()
{
    // parameters
    bool running = true;
    string input_answer = "";

    // main loop
    while(running)
    {
        // user object definitions
        cout << "============================================================================================================================" << endl;
        cout << "[1] Start Test : ";

        // print all objects (printinfo)
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "[x] Do you want to print out your stored objects? (y/n) : ";
        cin >> input_answer;

        if(((input_answer == "y") || (input_answer == "Y")))
        {
            //...
        }
        input_answer = "";

        // ask user if more objects should be stored
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "[x] Do you want to store another object? (y/n) : ";
        cin >> input_answer;

        if(!((input_answer == "y") || (input_answer == "Y")))
        {
            running = false;
        }
    }
    cout << "============================================================================================================================" << endl;
    return 0;
}
