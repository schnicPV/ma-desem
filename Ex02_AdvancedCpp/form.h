#ifndef FORM_H
#define FORM_H

#include <string>
#include "point.h"

using namespace std;

namespace color
{
	enum colorList
	{
		blue, purple, yellow
	};

	string toString(colorList color);
}

class Form
{
public:
	Form(const Point & tl, const Point & br, color::colorList cl);

protected:
	Point _topLeft;
	Point _bottonRight;
	color::colorList _color;
};

#endif // FORM_H
