#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "point.h"
#include "interface.h"

using namespace std;

namespace color
{
	enum colorList
	{
		blue, purple, yellow
	};

	string toString(colorList color);
	colorList getColorFromString(string colorName);
}

class Form : public Interface
{
public:
	Form(const Point & tl, const Point & br, color::colorList cl);
	virtual void printInfo();

protected:
	Point _topLeft;
	Point _bottonRight;
	color::colorList _color;
};

#endif // FORM_H
