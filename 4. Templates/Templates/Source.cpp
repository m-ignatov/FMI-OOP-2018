#include <iostream>
#include "Template.h"

int main()
{
	double arr[] = { 1, 2, 3, 4, 5, 6, 20 };
	int size = sizeof(arr) / sizeof(double);

	const int newSize = 4;
	double* arr2 = new double[newSize];
	arr2 = take(arr, size, newSize);
	std::cout << "Sum of first 4 elements of main collection: " << accumulates(arr2, newSize) << "\n\n";

	std::cout << average(arr, size) << '\n';
	std::cout << mode(arr, size) << '\n';
	std::cout << median(arr, size) << '\n';
	std::cout << accumulates(arr, size) << '\n';
	std::cout << max(arr, size) << '\n';
	std::cout << min(arr, size) << '\n';
}