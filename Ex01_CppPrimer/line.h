/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            line
* Purpose:          Build a line object
* Inheritance:      "line" is a child of "forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <string>
#include "forms.h"

// definition of the class 'Line', which inherits from the class 'Forms'
class Line : public Forms
{
    public:
        Line(Point pUL, Point pLR, color col);
        void printInfo();
};

#endif