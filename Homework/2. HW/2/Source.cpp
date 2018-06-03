#include <iostream>
#include "Settings.h"

int main()
{
	Settings<int> s;
	int dummy = 0, dummy2 = 0;

	s.set("Set1", 23);
	s.set("Set2", 54);
	s.set("Set3", 44);

	std::cout << "Settings Counter: " << s.count() << '\n';

	s.get("Set1", dummy);
	std::cout << dummy << '\n';

	s.get("DummySet", dummy2);
	std::cout << dummy2 << '\n';

}