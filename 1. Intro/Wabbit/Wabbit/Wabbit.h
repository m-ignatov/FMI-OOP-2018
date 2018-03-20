#pragma once

enum sex
{
	male,
	female,
	vampire
};

const int totalSexes = 3;

enum color
{
	black,
	yellow,
	red,
	blue
};

const int totalColors = 4;

class Wabbit
{
private:
	size_t age;
	sex mySex;
	color myColor;

public:
	Wabbit();
	Wabbit(const int& _age, const sex& _mySex, const color& _myColor);

	void print() const;

	void changeWabbitSex();
	void setAge(const size_t& age);
	void setSex(const sex& mySex);
	void setColor(const color& myColor);

	const int& getAge() const;
	const sex& getSex() const;
	const color& getColor() const;
};