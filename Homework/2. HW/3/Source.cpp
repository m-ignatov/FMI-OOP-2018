#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"

int main()
{
	Car c("Porsche", "911", "Black", 2010, 24444);
	Car c1;
	c1.details();
	c1 = c;
	c1.details();
	
	Truck t1("MAN", "Tour", "Red", 2004, 7269134, 33);
	Truck t2 = t1;
	t1.details();
	t2.setMake("Mile Kitic");
	t2.setModel("Milioni, Kamioni");
	t2.details();

	Motorcycle m1("Honda", "CBR1000F", "Gray", 1987, 4897, "motorcycle");
	Motorcycle m2 = m1;
	m1.details();
	m2.setType("Sport touring");
	m2.details();
}