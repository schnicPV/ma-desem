#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle(const Point & tl, const Point & br, color::colorList cl)
 : Form(tl, br, cl)
{
}

void Circle::printInfo()
{
	const uint32_t rx = (_bottonRight.x() - _topLeft.x()) / 2;		// Calculate radius on x axis
	const uint32_t ry = (_bottonRight.y() - _topLeft.y()) / 2;		// Calculate radius on y axis
	const Point centerPoint(_topLeft.x() + rx, _topLeft.y() + ry);	// Calculate center point

	if (rx == ry)
	{
		cout << "Circle with radius " << rx << " and center point " << centerPoint.toString() << " in " << color::toString(_color) << endl;
	}
	else
	{
		cout << "Ellipse with rx " << rx << ", ry " << ry << " with center point " << centerPoint.toString() << " in " << color::toString(_color) << endl;
	}
}
