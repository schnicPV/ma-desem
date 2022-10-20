/* 
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Module:           MA_DeSEm
* Chapter:          C++ primer
* Exercicse:        #1
* Author:           schnic
* Creation Date:    2022/10/06
* -----------------------------------------------------------------------------------------------------------------------------------------------*
* Class:            Point
* Purpose:          Store 2 values, which form a 2D point
* -----------------------------------------------------------------------------------------------------------------------------------------------*
*/
#ifndef POINT_H
#define POINT_H

// definition of the class structure
class Point
{
    public:
        Point();
        Point(float cX, float cY);

        float x;
        float y;
};

#endif