#ifndef LINE_H
#define LINE_H

#include "form.h"

class Line : public Form
{
public:
	Line(const Point & tl, const Point & br, color::colorList cl);
	virtual void printInfo();
};

#endif // LINE_H
