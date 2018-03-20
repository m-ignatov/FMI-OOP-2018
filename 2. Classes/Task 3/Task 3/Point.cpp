#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const double & _x, const double & _y) : x(_x), y(_y) {}

const double Point::getX() const
{
	return x;
}

const double Point::getY() const
{
	return y;
}

void Point::setX(const double & _x)
{
	x = _x;
}

void Point::setY(const double & _y)
{
	y = _y;
}


