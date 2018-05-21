#include <iostream>
#include "Pencil.h"
#include "Marker.h"
#include "WritingInstrument.h"

int main()
{
	Marker m("Markerz", 1905, "black");
	Pencil p;

	std::cin >> p;
	std::cout << p;
	std::cout << m;
}