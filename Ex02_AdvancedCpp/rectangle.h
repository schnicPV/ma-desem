#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "form.h"

class Rectangle : public Form
{
public:
	Rectangle(const Point & tl, const Point & br, color::colorList cl);
	void printInfo() const;
};

#endif // RECTANGLE_H
