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
    float deltaX = abs(pUL.x - pLR.x);
    float deltaY = abs(pUL.y - pLR.y);

    if(deltaX != deltaY)
    {
        Forms::type = "ELLIPSE";
        radius = -1.0f;
        circumference = -1.0f;
        surface = PI*deltaX*deltaY*0.25;
    } else
    {
        Forms::type = "CIRCLE";
        radius = deltaX*0.5;
        circumference = 2*PI*radius;
        surface = PI*radius*radius;
    }
    
}

void Circle::printInfo()
{
    Forms::printInfo();
    std::cout << "=> radius = " << radius << ", circumference = " << circumference << ", surface = " << surface << "\n";
}