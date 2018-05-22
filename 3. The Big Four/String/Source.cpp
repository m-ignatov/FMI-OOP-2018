#include <iostream>
#include "String.h"

int main()
{
	String s = "Johnnyy";
	String s1 = "Johnny";
	String s2;

	std::cin >> s2;
	std::cout << s2;
	
	s2 = s;

	if (s2 == s1) std::cout << "Equal!\n";
	else std::cout << "Not equal!\n";

	std::cout << s2;
	std::cout << s + s1;
}