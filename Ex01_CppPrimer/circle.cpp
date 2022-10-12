/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/12
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Circle
* Purpose:          Build a circle object
* Inheritance:      "Circle" is a child of "Forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#include "circle.h"

Circle::Circle(Point pUL, Point pLR, color col) : Forms(pUL, pLR, col)
{
    Forms::type = "CIRCLE";
}

void Circle::printInfo()
{
    Forms::printInfo();
}