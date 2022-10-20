#ifndef POINT_H
#define POINT_H

#include <stdint.h>
#include <string>

using namespace std;

class Point
{
public:
	Point(uint32_t x = 0, uint32_t y = 0);

	uint32_t x() const;
	void setX(uint32_t value);

	uint32_t y() const;
	void setY(uint32_t value);

	string toString() const;

protected:
	uint32_t _x;
	uint32_t _y;
};

#endif // POINT_H
