#pragma once
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle
{
public:
	Car();
	Car(const Car&);
	Car(const char*, const char*, const char*, const int&, const int&);
	Car& operator=(const Car&);
	~Car();

	void details() const;
};