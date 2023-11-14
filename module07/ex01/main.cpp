#include <iostream>
#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);

	std::cout << "Printing integers: ";
	iter(intArray, intArrayLength, printElement<int>);
	iter(intArray, intArrayLength, multipleTwice<int>);
	std::cout << "\n" << "x2: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

	std::cout << "Printing doubles: ";
	iter(doubleArray, doubleArrayLength, printElement<double>);
	iter(doubleArray, doubleArrayLength, multipleTwice<double>);
	std::cout << "\n" << "x2: ";
	iter(doubleArray, doubleArrayLength, printElement<double>);
	std::cout << std::endl;

	return 0;
}