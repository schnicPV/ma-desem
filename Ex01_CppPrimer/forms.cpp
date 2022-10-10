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
#include "forms.h"
#include <iostream>
using namespace std;

#include <string>

// definition of the constructor
Forms::Forms(Point pUL, Point pLR, color col)
{
    uL = pUL;
    lR = pLR;
    clr = col;
}

// definition of the geInfo function
void Forms::printInfo()
{
    cout << "I am a " << /*Forms::decodeColor(clr)*/ clr << " " << type << " between Point1 (" << this->uL.x << " | " << this->uL.y << ") and Point2 (" << this->lR.x << " | " << this->lR.y << ")\n";
}

// std::string decodeColor(color in)
// {
//     string retStr = "";
//     switch(in) {
//         case red:
//             retStr = "red";
//             break;
//         case blue:
//             retStr = "blue";
//             break;
//         case green:
//             retStr = "green";
//             break;
//         case yellow:
//             retStr = "yellow";
//             break;
//         case purple:
//             retStr = "purple";
//             break;
//         default:
//             retStr = "undef";
//             break;
//     }
//     return retStr;
// }