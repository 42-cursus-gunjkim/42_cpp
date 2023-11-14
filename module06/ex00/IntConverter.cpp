#include "IntConverter.hpp"

void IntConverter::convert(long l)
{
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "int: Overflow\n";
	else
	{
		int i = static_cast<int>(l);
		std::cout << "int: " << i << "\n";
	}
}

void IntConverter::convert(char c)
{
	long l = static_cast<long>(c);
	IntConverter::convert(l);
}

void IntConverter::convert(float f)
{
	int casted = static_cast<int>(f);
	if (isnan(f) == true || isinf(f) == true)
		std::cout << "int: Impossible\n";
	else if ((casted < 0 && f > 0) || (casted > 0 && f < 0))
		std::cout << "int: Overflow\n";
	else
		std::cout << "int: " << casted << "\n";
}

void IntConverter::convert(double d)
{
	int casted = static_cast<int>(d);
	if (isnan(d) == true || isinf(d) == true)
		std::cout << "int: Impossible\n";
	else if ((casted < 0 && d > 0) || (casted > 0 && d < 0))
		std::cout << "int: Overflow\n";
	else
		std::cout << "int: " << casted << "\n";
}