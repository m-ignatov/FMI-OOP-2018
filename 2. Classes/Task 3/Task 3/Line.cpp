#include "Line.h"

Line::Line() : A(Point()), B(Point()) {}

Line::Line(const Point & _a, const Point & _b) : A(_a), B(_b) {}

const Point Line::getA() const
{
	return A;
}

const Point Line::getB() const
{
	return B;
}

const double Line::getGradient() const
{
	if (A.getX() - B.getX() == 0) return 0;
	return (A.getY() - B.getY()) / (A.getX() - B.getX());
}

const double Line::getYIntercept() const
{
	return A.getY() - A.getX() * getGradient();
}

void Line::setA(const Point & _a)
{
	A = _a;
}

void Line::setB(const Point & _b)
{
	B = _b;
}

bool Line::isParallel(const Line & sec)
{
	if (getGradient() == sec.getGradient()) return true;
	return false;
}

bool Line::isFromLine(const Point & pt)
{
	double a = getGradient();
	double b = getYIntercept();

	if ((pt.getX()*a + b) == pt.getY()) return true;
	return false;
}

Point Line::crossPoint(const Line & sec)
{
	if (isParallel(sec)) return Point(0.000000001, 0.00000000001);

	double a = getGradient();
	double b = getYIntercept();
	double c = sec.getGradient();
	double d = sec.getYIntercept();

	int x = (b - d) / (a + c);
	int y = a * x + b;

	return Point(x, y);
}
