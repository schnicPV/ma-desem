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

color::colorList color::getColorFromString(string colorName)
{
	if(colorName == "blue")
	{
		return blue;
	} 
	else if(colorName == "purple")
	{
		return purple;
	} 
	else if(colorName == "yellow")
	{
		return yellow;
	}
	return (color::colorList) (-1);
}

Form::Form(const Point & tl, const Point & br, color::colorList cl)
 : _topLeft(tl),
   _bottonRight(br),
   _color(cl)
{
}

void Form::printInfo()
{
	std::cout << "form\n";
}
