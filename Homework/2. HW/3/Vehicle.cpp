#include "Vehicle.h"
#include <cstring>
#include<iostream>

Vehicle::Vehicle() : year(0), mileage(0)
{
	make = new char{ '\0' };
	model = new char{ '\0' };
	color = new char{ '\0' };
}

Vehicle::Vehicle(const Vehicle & rhs) : year(rhs.year), mileage(rhs.mileage)
{
	this->make = new char[strlen(rhs.make) + 1];
	strcpy(this->make, rhs.make);
	
	this->model = new char[strlen(rhs.model) + 1];
	strcpy(this->model, rhs.model);

	this->color = new char[strlen(rhs.color) + 1];
	strcpy(this->color, rhs.color);
}

Vehicle::Vehicle(const char * make, const char * model, const char * color, const int & year, const int & mileage)
{
	setYear(year);
	setMileage(mileage);
	
	this->make = new char[strlen(make) + 1];
	strcpy(this->make, make);

	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);

	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

Vehicle & Vehicle::operator=(const Vehicle & rhs)
{
	if (this != &rhs)
	{
		setYear(rhs.year);
		setMileage(rhs.mileage);
		setModel(rhs.model);
		setMake(rhs.make);
		setColor(rhs.color);
	}
	return *this;
}

Vehicle::~Vehicle()
{
	delete[] make;
	delete[] model;
	delete[] color;
}

void Vehicle::setMake(const char * make)
{
	delete[] this->make;
	this->make = new char[strlen(make) + 1];
	strcpy(this->make, make);
}

void Vehicle::setModel(const char * model)
{
	delete[] this->model;
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}

void Vehicle::setColor(const char * color)
{
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

void Vehicle::setYear(const int & year)
{
	this->year = year;
}

void Vehicle::setMileage(const int & mileage)
{
	this->mileage = mileage;
}

const char * Vehicle::getMake() const
{
	return make;
}

const char * Vehicle::getModel() const
{
	return model;
}

const char * Vehicle::getColor() const
{
	return color;
}

const int & Vehicle::getYear() const
{
	return year;
}

const int & Vehicle::getMileage() const
{
	return mileage;
}
