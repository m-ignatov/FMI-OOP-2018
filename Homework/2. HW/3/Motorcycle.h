#pragma once
#include "Vehicle.h"

class Motorcycle :public Vehicle
{
private:
	char* type;

public:
	Motorcycle();
	Motorcycle(const Motorcycle&);
	Motorcycle(const char*, const char*, const char*, const int&, const int&, const char*);
	Motorcycle& operator=(const Motorcycle&);
	~Motorcycle();

	void setType(const char*);
	const char* getType();
	void details() const;
};