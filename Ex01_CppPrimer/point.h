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
#ifndef POINT_H
#define POINT_H

// definition of the class structure
class Point
{
    public:
        Point(float cX, float cY);

    protected:
        float x;
        float y;
};

#endif