/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            forms
* Purpose:          Build the parent class of all different forms
* Inheritance:      "forms" is the parent of "line", "rectangle", "circle"
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#include "forms.h"
#include <iostream>
using namespace std;
#include <string>

// definition of the constructor
Forms::Forms(Point pUL, Point pLR, color col)
{
    uL = pUL;
    lR = pLR;
    clr = col;
}

// definition of function to transform color to string (used to print out color)
std::string Forms::col2str(color in)
{
    string retStr = "";
    switch(in) {
        case red:
            retStr = "red";
            break;
        case blue:
            retStr = "blue";
            break;
        case green:
            retStr = "green";
            break;
        case yellow:
            retStr = "yellow";
            break;
        case purple:
            retStr = "purple";
            break;
        default:
            retStr = "undef";
            break;
    }
    return retStr;
}

// definition of functions to transform point components to string
std::string Forms::point2str(Point in)
{
    std::string ret = "(" + std::to_string(in.x) + " | " + std::to_string(in.y) + ")";
    return ret;
}

// definition of the geInfo function
void Forms::printInfo()
{
    cout << "I'm a " << this->col2str(clr) << " " << type << " between Point1 " << this->point2str(uL) << " and Point2 " << this->point2str(lR) << "\n";
}
