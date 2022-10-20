#ifndef CIRCLE_H
#define CIRCLE_H

#include "form.h"

class Circle : public Form
{
public:
	Circle(const Point & tl, const Point & br, color::colorList cl);
	void printInfo() const;
};

#endif // CIRCLE_H
