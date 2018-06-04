#include "ElectricNet.h"
#include <cstring>
#include <iostream>
#include <cassert>

void ElectricNet::resize()
{
	ElectricDevice * newCluster = new ElectricDevice[maxSize * 2];

	for (size_t i = 0; i < size; i++)
	{
		newCluster[i] = cluster[i];
	}

	maxSize *= 2;
	delete[] cluster;
	cluster = newCluster;
}

ElectricNet::ElectricNet() : curConsumption(0), maxSize(1), maxConsumption(100), size(0), cluster(new ElectricDevice[1]) {}

ElectricNet::ElectricNet(const ElectricNet &rhs)
{
	curConsumption = rhs.getCurConsumption();
	maxConsumption = rhs.getMaxConsumption();
	maxSize = rhs.getMaxSize();
	cluster = new ElectricDevice[rhs.getSize()];

	for (size_t i = 0; i < rhs.getSize(); i++)
	{
		cluster[i] = rhs[i];
	}
}

ElectricNet & ElectricNet::operator=(const ElectricNet &rhs)
{
	if (this != &rhs)
	{
		delete[] cluster;
		ElectricNet(rhs);
	}
	return *this;
}

ElectricNet & ElectricNet::operator+(const ElectricDevice &rhs)
{
	if (size + 1 > maxSize) resize();

	if (maxConsumption < curConsumption + rhs.getConsumption())
	{
		std::cout << "Consumption overload!";
	}
	cluster[size++] = rhs;
	curConsumption += rhs.getConsumption();

	return *this;
}

ElectricNet& ElectricNet::operator++()
{
	maxConsumption *= 2;
	return *this;
}

ElectricNet& ElectricNet::operator++(int)
{
	ElectricNet tmp(*this);
	operator++();
	return tmp;
}

ElectricNet& ElectricNet::operator--()
{
	if (curConsumption >= 2 * maxConsumption) maxConsumption /= 2;
	return *this;
}

ElectricNet& ElectricNet::operator--(int)
{
	ElectricNet tmp(*this);
	operator--();
	return tmp;
}

ElectricNet & ElectricNet::operator+=(const ElectricDevice &rhs)
{
	return (*this + rhs);
}

ElectricNet & ElectricNet::operator-(const ElectricDevice &rhs)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(rhs.getName(), cluster[i].getName()))
		{
			curConsumption -= rhs.getConsumption();
			size--;
			for (size_t j = i; j < size; j++)
			{
				cluster[j] = cluster[j + 1];
			}
			break;
		}
	}
	return *this;
}

ElectricNet & ElectricNet::operator-=(const ElectricDevice &rhs)
{
	return (*this - rhs);
}

ElectricDevice & ElectricNet::operator[](const char *c) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(cluster[i].getName(), c)) return cluster[i];
	}
	std::cout << "No device with name " << c << " found!\n";
	exit(1);
}

ElectricDevice & ElectricNet::operator[](const int &i) const
{
	if (i < 0 || i >= size)
	{
		std::cout << "Error: Out of bounds!\n";
		exit(1);
	}
	return cluster[i];
}

bool ElectricNet::operator!()
{
	if (size) return true;
	return false;
}

unsigned int ElectricNet::getCurConsumption() const
{
	return curConsumption;
}

unsigned int ElectricNet::getMaxConsumption() const
{
	return maxConsumption;
}

unsigned int ElectricNet::getSize() const
{
	return size;
}

unsigned int ElectricNet::getMaxSize() const
{
	return maxSize;
}
