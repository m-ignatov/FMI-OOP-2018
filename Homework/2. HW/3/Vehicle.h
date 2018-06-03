#pragma once

class Vehicle
{
private:
	char* make;
	char* model;
	char* color;
	int year;
	int mileage;

public:
	Vehicle();
	Vehicle(const Vehicle&);
	Vehicle(const char*, const char*, const char*, const int&, const int&);
	Vehicle& operator=(const Vehicle&);
	~Vehicle();

	virtual void details() const = 0;

	void setMake(const char*);
	void setModel(const char*);
	void setColor(const char*);
	void setYear(const int&);
	void setMileage(const int&);
	const char* getMake() const;
	const char* getModel() const;
	const char* getColor() const;
	const int& getYear() const;
	const int& getMileage() const;
};