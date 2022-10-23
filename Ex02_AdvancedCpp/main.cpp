#include <iostream>
using namespace std;
#include <vector>

#include "line.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    // parameters
    bool running = true;
    vector<Form*> formVec;     // store all entered objects into a vector

    // user input values
    string input_type;
    string input_color;
    string input_answer;
    uint32_t input_tlX;
    uint32_t input_tlY;
    uint32_t input_brX;
    uint32_t input_brY;

    while(running)
    {
        input_type = "";
        input_color = "";
        input_answer = "";
        input_tlX = 0;
        input_tlY = 0;
        input_brX = 0;
        input_brY = 0;

        // user object definitions
        cout << "============================================================================================================================" << endl;
        cout << "[1] Type your object TYPE (line/rectangle/circle) : ";
        cin >> input_type;
        cout << "[2] Type the COLOR of your object (blue/yellow/purple) : ";
        cin >> input_color;
        cout << "[3] Type the X coordinate of the TOP LEFT corner of your object (integer) : ";
        cin >> input_tlX;
        cout << "[4] Type the Y coordinate of the TOP LEFT corner of your object (integer) : ";
        cin >> input_tlY;
        cout << "[5] Type the X coordinate of the BOTTOM RIGHT corner of your object (integer) : ";
        cin >> input_brX;
        cout << "[6] Type the Y coordinate of the BOTTOM RIGHT corner of your object (integer) : ";
        cin >> input_brY;

        // add new object to list
        if((input_type == "line") || (input_type == "Line"))
        {
            formVec.push_back(new Line(Point(input_tlX,input_tlY),Point(input_brX,input_brY),color::getColorFromString(input_color)));
        } 
        else if((input_type == "rectangle") || (input_type == "Rectangle"))
        {
            formVec.push_back(new Rectangle(Point(input_tlX,input_tlY),Point(input_brX,input_brY),color::getColorFromString(input_color)));
        }
        else if((input_type == "circle") || (input_type == "Circle"))
        {
            formVec.push_back(new Circle(Point(input_tlX,input_tlY),Point(input_brX,input_brY),color::getColorFromString(input_color)));
        }
        else
        {
            cout << "\n[ERROR] invalid form input!" << endl;
        }

        // print all objects (printinfo)
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "[x] Do you want to print out your stored objects? (y/n) : ";
        cin >> input_answer;

        if(((input_answer == "y") || (input_answer == "Y"))) 
        {
            for(int vIdx = 0; vIdx < formVec.size(); vIdx++)
            {
                cout << "[object No " << vIdx+1 << "] ";
                formVec[vIdx]->printInfo();
            }
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

