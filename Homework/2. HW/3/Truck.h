#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	int size;

public:
	Truck();
	Truck(const Truck&);
	Truck(const char*, const char*, const char*, const int&, const int&, const int&);
	Truck& operator=(const Truck&);
	~Truck();

	void details() const;
};