#include "DoubleConverter.hpp"

void DoubleConverter::convert(double d)
{
	std::cout << std::fixed << "double: " << d << "\n";
}

void DoubleConverter::convert(float f)
{
	double d = static_cast<double>(f);
	std::cout << std::fixed << "double: " << d << "\n";
}

void DoubleConverter::convert(char c)
{
	double d = static_cast<double>(c);
	std::cout << std::fixed << "double: " << d << "\n";
}

void DoubleConverter::convert(int i)
{
	double d = static_cast<double>(i);
	std::cout << std::fixed << "double: " << d << "\n";
}
