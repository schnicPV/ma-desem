#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(const Point & tl, const Point & br, color::colorList cl)
 : Form(tl, br, cl)
{
}

void Rectangle::printInfo() const
{
	cout << "Rectangle from " << _topLeft.toString() << " to " << _bottonRight.toString()<< " in " << color::toString(_color) << endl;
}
