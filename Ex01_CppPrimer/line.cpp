/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/03
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Line
* Purpose:          Build a line object
* Inheritance:      "Line" is a child of "Forms" 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#include "line.h"

Line::Line(Point pUL, Point pLR, color col) : Forms(pUL, pLR, col)
{
    Forms::type = "LINE";
    length = powf(powf(pUL.x - pLR.x, 2) + powf(pUL.y - pLR.y, 2), 0.5);
}

void Line::printInfo()
{
    Forms::printInfo();
    std::cout << "=> the length is: " << length << "\n";
}