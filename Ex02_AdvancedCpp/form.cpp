#include "form.h"

string color::toString(colorList color)
{
	switch (color)
	{
	case blue:
		return "blue";
		break;
	case purple:
		return "purple";
		break;
	case yellow:
		return "yellow";
		break;
	}
	return "unknown color";
}

Form::Form(const Point & tl, const Point & br, color::colorList cl)
 : _topLeft(tl),
   _bottonRight(br),
   _color(cl)
{
}
