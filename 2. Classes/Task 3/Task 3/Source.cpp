#include <iostream>
#include <iomanip>
#include "Line.h"

int main()
{
	Line A(Point(1, 2), Point(0, 0));
	Line B(Point(0, 0), Point(0, 2));
	Point pt(0, 0);

	if (A.isParallel(B)) std::cout << "Line A is parallel to B" << std::endl;
	else std::cout << "Line A is not parallel to B" << std::endl;

	if (A.isFromLine(pt)) std::cout << "Point is parallel to Line A" << std::endl;
	else std::cout << "Point is not parallel to Line A" << std::endl;

	Point cp = A.crossPoint(B);
	std::cout << "Cross point (" << std::fixed << std::setprecision(2) << cp.getX() << ", " << cp.getY() << ")" << std::endl;
}