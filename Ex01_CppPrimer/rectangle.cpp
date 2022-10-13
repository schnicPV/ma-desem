/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/12
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Rectangle
* Purpose:          Build a rectangle object
* Inheritance:      "Rectangle" is a child of "Forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#include "rectangle.h"

Rectangle::Rectangle(Point pUL, Point pLR, color col) : Forms(pUL, pLR, col)
{
    float deltaX = abs(pUL.x - pLR.x);
    float deltaY = abs(pUL.y - pLR.y);
    
    Forms::type = "RECTANGLE";
    circumference = 2*(deltaX + deltaY);
    surface = deltaX*deltaY;
}

void Rectangle::printInfo()
{
    Forms::printInfo();
    std::cout << "=> circumference = " << circumference << ", surface = " << surface << "\n";
}