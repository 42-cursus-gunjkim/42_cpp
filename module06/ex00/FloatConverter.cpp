#include "FloatConverter.hpp"

void FloatConverter::convert(float f)
{
	std::cout << std::fixed << "float: " << f << "\n";
}

void FloatConverter::convert(char c)
{
	float f = static_cast<float>(c);
	std::cout << std::fixed << "float: " << f << "\n";
}

void FloatConverter::convert(int i)
{
	float f = static_cast<float>(i);
	std::cout << std::fixed << "float: " << f << "\n";
}

void FloatConverter::convert(double d)
{
	float f = static_cast<float>(d);
	std::cout << std::fixed << "float: " << f << "\n";
}
