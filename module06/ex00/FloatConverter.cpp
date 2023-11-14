#include "FloatConverter.hpp"

void FloatConverter::convert(float f)
{
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
}

void FloatConverter::convert(char c)
{
	float f = static_cast<float>(c);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
}

void FloatConverter::convert(long l)
{
	float f = static_cast<float>(l);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
}

void FloatConverter::convert(double d)
{
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
}
