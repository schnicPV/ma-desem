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
* Inheritance:      "Forms" is the parent of "Line", "Rectangle", "Circle"
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
const char* Forms::col2str(int enumVal)
{
    return colStr[enumVal];
}

// definition of function to transform point components to string
std::string Forms::point2str(Point in)
{
    return "(" + std::to_string(in.x) + "|" + std::to_string(in.y) + ")";
}

// definition of the printInfo function
void Forms::printInfo()
{
    cout << "A " << col2str(clr) << " " << type << " between Point" << point2str(uL) << " and Point" << point2str(lR) << "\n";
}
