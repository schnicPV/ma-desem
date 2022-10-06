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
#include <iostream>
#include "forms.h"

Forms::Forms(Point pUL, Point pLR, color col)
{
    uL = pUL;
    lR = pLR;
    clr = col;
}

Forms::getInfo()
{
    cout << "I am a form";
}