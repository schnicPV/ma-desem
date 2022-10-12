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
}

void Line::printInfo()
{
    Forms::printInfo();
}