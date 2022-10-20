#ifndef LINE_H
#define LINE_H

#include "form.h"

class Line : public Form
{
public:
	Line(const Point & tl, const Point & br, color::colorList cl);
	void printInfo() const;
};

#endif // LINE_H
