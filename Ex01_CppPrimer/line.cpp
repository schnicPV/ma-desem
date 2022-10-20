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
    float deltaX = abs(pUL.x - pLR.x);
    float deltaY = abs(pUL.y - pLR.y);
    
    Forms::type = "LINE";
    length = powf(powf(deltaX, 2) + powf(deltaY, 2), 0.5);
}

void Line::printInfo()
{
    Forms::printInfo();
    std::cout << "=> length = " << length << "\n";
}