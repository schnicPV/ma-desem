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
#ifndef FORMS_H
#define FORMS_H

#include <string>
// #include <iostream>
// using namespace std;

#include "point.h"

// color definition
enum color
{
    red, blue, green, yellow, purple
};

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
};

#endif