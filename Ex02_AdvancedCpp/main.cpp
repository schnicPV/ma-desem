#include <iostream>
using namespace std;

#include "line.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    // new interactive ex 2
    Form* pBase;
    bool running = true;

    // user values
    string input_type;
    string input_color;
    string input_answer;
    uint32_t input_tlX;
    uint32_t input_tlY;
    uint32_t input_brX;
    uint32_t input_brY;

    // TODO: list to store all objects

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
        cout << "[1] Type your object TYPE:" << endl;
        cin >> input_type;
        cout << "[2] Type the COLOR of your object:" << endl;
        cin >> input_color;
        cout << "[3] Type the X coordinate of the TOP LEFT corner of your object:" << endl;
        cin >> input_tlX;
        cout << "[4] Type the Y coordinate of the TOP LEFT corner of your object:" << endl;
        cin >> input_tlY;
        cout << "[5] Type the X coordinate of the BOTTOM RIGHT corner of your object:" << endl;
        cin >> input_tlX;
        cout << "[6] Type the Y coordinate of the top BOTTOM RIGHT of your object:" << endl;
        cin >> input_tlY;

        // TODO: create object

        // TODO: add object to a list 

        // print all objects (printinfo)
        cout >> "[x] Do you want to print out your stored objects? (y/n)" << endl;
        cin >> input_answer;

        if(((input_answer == "y") || (input_answer == "Y"))) 
        {
            // insert for loop
        }
        input_answer = "";

        // ask user if more objects should be stored
        cout << "[x] Do you want to store another object? (y/n)" << endl;
        cin >> input_answer;

        if(!((input_answer == "y") || (input_answer == "Y"))) 
        {
            running = false;
        }
    }

    // old ex 1
    Line l1(Point(10,10),Point(40,40), color::blue);
    Rectangle r1(Point(10,50),Point(40,90), color::purple);
    Circle c1(Point(10,90),Point(40,140), color::yellow);

    l1.printInfo();
    r1.printInfo();
    c1.printInfo();

    return 0;
}

