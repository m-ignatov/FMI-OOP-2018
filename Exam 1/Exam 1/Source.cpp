#include <iostream>
#include "House.h"

int main()
{
	House h1(1, 9, 8, 4, "John"), h2(5, 6, 7, 8, "Johhny");
	House h3 = h1;
	h3.setOwner("Peter");

	std::cout << h1;
	std::cout << h2;
	std::cout << h3;
	std::cout << "Total area of House 2: " << h2.getTotalArea() << '\n';

	if ((Building&)h1 < (Building&)h2) std::cout << "House 1 has less area than House 2\n";
	else std::cout << "House 2 has less area than House 1\n";

	if (h1 < h2) std::cout << "House 1 has less rooms than House 2\n";
	else std::cout << "House 2 has less rooms than House 1\n";
}