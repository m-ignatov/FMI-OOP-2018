#include "ElectricDevice.h"
#include <cstring>
#pragma warning(disable:4996)

ElectricDevice::ElectricDevice() : consumption(0)
{
	setName("");
}

ElectricDevice::ElectricDevice(const char * _name, const unsigned int & _consumption) : consumption(_consumption)
{
	setName(_name);
}

ElectricDevice::ElectricDevice(const ElectricDevice &rhs) : consumption(rhs.getConsumption())
{
	setName(rhs.getName());
}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice &rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		setName(rhs.getName());
		consumption = rhs.getConsumption();
	}
	return *this;
}

ElectricDevice::~ElectricDevice()
{
	delete[] name;
}

const char * ElectricDevice::getName() const
{
	return name;
}

void ElectricDevice::setName(const char * _name)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

const unsigned int ElectricDevice::getConsumption() const
{
	return consumption;
}

void ElectricDevice::setConsumption(const unsigned int &_consumption)
{
	consumption = _consumption;
}
