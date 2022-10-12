/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Forms
* Purpose:          Build the parent class of all different forms
* Inheritance:      "Forms" is the parent of "Line", "Rectangle", "Circle"
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#ifndef FORMS_H
#define FORMS_H

#include <string>
#include "point.h"

// color definition
enum color
{
    red, blue, green, yellow, purple
};

// strings of color definitions, used to print out names of enumerations
static const char* colStr[] = {"red", "blue", "green", "yellow", "purple"};

// definition of the class structure
class Forms
{
    public:
        Forms(Point pUL, Point pLR, color col);
        void printInfo();

    protected:
        Point uL;
        Point lR;
        color clr;
        std::string type;

        const char* col2str(int enumVal);
        std::string point2str(Point in);
};

#endif