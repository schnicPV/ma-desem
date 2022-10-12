/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Circle
* Purpose:          Build a circle object
* Inheritance:      "Circle" is a child of "Forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "forms.h"

// definition of the class 'Circle', which inherits from the class 'Forms'
class Circle : public Forms
{
    public:
        Circle(Point pUL, Point pLR, color col);
        void printInfo();
};

#endif