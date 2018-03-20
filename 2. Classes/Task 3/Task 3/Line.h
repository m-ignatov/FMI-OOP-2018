#pragma once
#include "Point.h"

class Line
{
private:
	Point A;
	Point B;

public:
	Line();
	Line(const Point& _a, const Point& _b);

	const Point getA() const;
	const Point getB() const;
	void setA(const Point& _a);
	void setB(const Point& _b);
	const double getGradient() const;
	const double getYIntercept() const;

	bool isParallel(const Line& sec);
	bool isFromLine(const Point& pt);
	Point crossPoint(const Line& sec);
};