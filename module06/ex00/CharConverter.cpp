#include "CharConverter.hpp"

void CharConverter::convert(char c)
{
	if (c >= CHAR_MIN && c <= 32)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << c << "\n";
}

void CharConverter::convert(int i)
{
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char: Overflow\n";
	else
	{
		char c = static_cast<char>(i);
		CharConverter::convert(c);
	}
}

void CharConverter::convert(float f)
{
	if (isnan(f) == true || isinf(f) == true)
		std::cout << "char: Impossible\n";
	else if (f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: Overflow\n";
	else
	{
		char c = static_cast<char>(f);
		CharConverter::convert(c);
	}
}

void CharConverter::convert(double d)
{
	if (isnan(d) == true || isinf(d) == true)
		std::cout << "char: Impossible\n";
	else if (d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: Overflow\n";
	else
	{
		char c = static_cast<char>(d);
		CharConverter::convert(c);
	}
}
