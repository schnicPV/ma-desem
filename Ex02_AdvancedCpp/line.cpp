#include <iostream>
#include "line.h"

using namespace std;

Line::Line(const Point & tl, const Point & br, color::colorList cl)
 : Form(tl, br, cl)
{
}

void Line::printInfo()
{
	cout << "Line from " << _topLeft.toString() << " to " << _bottonRight.toString() << " in " << color::toString(_color) << endl;
}
