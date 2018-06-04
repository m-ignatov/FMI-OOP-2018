#pragma once
#include "ElectricDevice.h"

class ElectricNet
{
private:
	ElectricDevice * cluster;
	unsigned int curConsumption;
	unsigned int maxConsumption;
	unsigned int size;
	unsigned int maxSize;

	void resize();

public:
	ElectricNet();
	ElectricNet(const ElectricNet&);
	ElectricNet& operator= (const ElectricNet&);
	
	bool operator! ();
	ElectricNet& operator++ ();
	ElectricNet& operator++ (int);
	ElectricNet& operator-- ();
	ElectricNet& operator-- (int);
	ElectricNet& operator+ (const ElectricDevice&);
	ElectricNet& operator+= (const ElectricDevice&);
	ElectricNet& operator- (const ElectricDevice&);
	ElectricNet& operator-= (const ElectricDevice&);
	ElectricDevice& operator[] (const char*) const;
	ElectricDevice& operator[] (const int&) const;

	unsigned int getCurConsumption() const;
	unsigned int getMaxConsumption() const;
	unsigned int getSize() const;
	unsigned int getMaxSize() const;
};