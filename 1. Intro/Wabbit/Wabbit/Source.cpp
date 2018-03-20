#include <iostream>
#include "Wabbit.h"

int main()
{
	Wabbit wabb(5, male, red);
	Wabbit dummy;

	dummy.print();

	wabb.print();
	wabb.changeWabbitSex();
	wabb.print();
}