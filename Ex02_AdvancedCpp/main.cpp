#include <iostream>
using namespace std;

#include "line.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
	Line l1(Point(10,10),Point(40,40), color::blue);
	Rectangle r1(Point(10,50),Point(40,90), color::purple);
	Circle c1(Point(10,90),Point(40,140), color::yellow);

	l1.printInfo();
	r1.printInfo();
	c1.printInfo();

	return 0;
}

