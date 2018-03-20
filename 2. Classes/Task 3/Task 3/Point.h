#pragma once

struct Point
{
private:
	double x;
	double y;

public:
	Point();
	Point(const double& _x, const double& _y);

	const double getX() const;
	const double getY() const;
	void setX(const double& _x);
	void setY(const double& _y);
};