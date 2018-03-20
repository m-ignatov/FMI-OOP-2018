#include "Wabbit.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


Wabbit::Wabbit() : age(0)
{
	srand(time(NULL));
	this->myColor = (color)(rand() % totalColors);
	this->mySex = (sex)(rand() % totalSexes);
}

Wabbit::Wabbit(const int & _age, const sex & _mySex, const color & _myColor) : age(_age), mySex(_mySex), myColor(_myColor) {}

void Wabbit::print() const
{
	switch (getColor())
	{
	case 0: std::cout << "Black ";
		break;
	case 1: std::cout << "Yellow ";
		break;
	case 2: std::cout << "Red ";
		break;
	case 3: std::cout << "Blue";
		break;
	default: std::cout << "Error!\n";
	}

	switch (getSex())
	{
	case 0: std::cout << "Male, ";
		break;
	case 1: std::cout << "Female, ";
		break;
	case 2: std::cout << "Vampire, ";
		break;
	default: std::cout << "Error!\n";
	}

	std::cout << getAge() << "\n\n";
}

void Wabbit::changeWabbitSex()
{
	if (age >= 6)
	{
		std::cout << "Cannot transform to vampire." << std::endl;
	}
	else
	{
		mySex = vampire;
		std::cout << "Successfully transformed to vampire." << std::endl;
	}
}

const int& Wabbit::getAge() const
{
	return age;
}

void Wabbit::setAge(const size_t& age)
{
	this->age = age;
}

const sex& Wabbit::getSex() const
{
	return mySex;
}

const color& Wabbit::getColor() const
{
	return myColor;
}

void Wabbit::setSex(const sex& mySex)
{
	this->mySex = mySex;
}

void Wabbit::setColor(const color& myColor)
{
	this->myColor = myColor;
}