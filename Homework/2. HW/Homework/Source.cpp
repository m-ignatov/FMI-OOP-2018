#include <iostream>
#include "ElectricNet.h"

int main()
{
	ElectricNet net;
	ElectricDevice d1("ED1", 23);
	net += d1;
	std::cout << d1.getName() << " " << d1.getConsumption() << '\n';
	
	ElectricDevice d2 = net["ED1"];
	d2.setName("ED2");
	net += d2;
	std::cout << d2.getName() << " " << d2.getConsumption() << '\n';

	net++;
	ElectricDevice d3 = d2;
	d3.setConsumption(100);
	d3.setName("ED3");
	net += d3;

	std::cout << net["ED3"].getName() << " " << net["ED3"].getConsumption() << '\n';

	net -= d2;
	std::cout << net["ED2"].getName() << " " << net["ED2"].getConsumption() << '\n';
} 