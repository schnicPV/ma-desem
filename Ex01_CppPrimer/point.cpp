/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/06
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            point
* Purpose:          Store 2 values, which form a 2D point
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#include "point.h"

// definition of the constructors
Point::Point()                          // default constructor
{

}

Point::Point(float cX, float cY)        // constructor to add the x,y values
{
    x = cX;
    y = cY;
}