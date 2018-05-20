#pragma once
#include <iostream>

class Building
{
private:
	unsigned int height;
	unsigned int area;
	unsigned int floors;

public:
	Building();
	Building(const unsigned int&, const unsigned int&, const unsigned int&);

	unsigned int getHeight() const;
	unsigned int getArea() const;
	unsigned int getFloors() const;
	void setHeight(const unsigned int&);
	void setArea(const unsigned int&);
	void setFloors(const unsigned int&);

	unsigned int getTotalArea() const;
	bool operator< (const Building&);
};

std::ostream& operator<<(std::ostream&, const Building&);