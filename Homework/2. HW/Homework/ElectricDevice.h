#pragma once
#include <iostream>
class ElectricDevice
{
private:
	char* name;
	unsigned int consumption;

public:
	ElectricDevice();
	ElectricDevice(const char*, const unsigned int&);
	ElectricDevice(const ElectricDevice&);
	ElectricDevice& operator=(const ElectricDevice&);
	~ElectricDevice();

	const char* getName() const;
	void setName(const char*);
	const unsigned int getConsumption() const;
	void setConsumption(const unsigned int&);
};
