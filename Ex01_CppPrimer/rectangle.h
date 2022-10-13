/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Rectangle
* Purpose:          Build a rectangle object
* Inheritance:      "Rectangle" is a child of "forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "forms.h"

// definition of the class 'Rectangle', which inherits from the class 'Forms'
class Rectangle : public Forms
{
    public:
        Rectangle(Point pUL, Point pLR, color col);
        float circumference;
        float surface;
        void printInfo();
};

#endif
