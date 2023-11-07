#include "ScalarConverter.hpp"

bool ifCharThenConvert(const std::string& literal)
{
	if (literal.length() == 1 && literal[0] >= CHAR_MIN && literal[0] <= CHAR_MAX)
	{
		char c = literal[0];
		CharConverter::convert(c);
		IntConverter::convert(c);
		FloatConverter::convert(c);
		DoubleConverter::convert(c);
		return true;
	}
	return false;
}

bool ifIntThenConvert(const std::string& literal)
{
	std::stringstream ss;
	int i;
	ss.str(literal);
	if (literal.find('.') == std::string::npos)
	{
		ss >> i;
		if (ss.fail() == false && ss.tellg() == -1)
		{
			CharConverter::convert(i);
			IntConverter::convert(i);
			FloatConverter::convert(i);
			DoubleConverter::convert(i);
			return true;
		}
	}
	return false;
}

bool ifFloatThenConvert(const std::string& literal)
{
	std::stringstream ss;
	std::string literalCopy = literal;
	float f;
	if (literal == "+inff")
		f = INFINITY;
	else if (literal == "-inff")
		f = -INFINITY;
	else if (literal == "nanf")
		f = 0/0.0f;
	else 
	{
		int literalLen = literal.length();
		if (literal.find('.') == std::string::npos
		|| literal.find('f') != literalLen - 1)
			return false;
		literalCopy.erase(literalCopy.end() - 1);
		ss.str(literalCopy);
		ss >> f;
		if (ss.fail() != false || ss.tellg() != -1)
			return false;
	}
	CharConverter::convert(f);
	IntConverter::convert(f);
	FloatConverter::convert(f);
	DoubleConverter::convert(f);
	return true;
}

bool ifDoubleThenConvert(const std::string& literal)
{
	std::stringstream ss;
	ss.str(literal);
	double d;
	if (literal == "+inf")
		d = INFINITY;
	else if (literal == "-inf")
		d = -INFINITY;
	else if (literal == "nan")
		d = 0/0.0f;
	else 
	{
		ss >> d;
		if (ss.fail() != false || ss.tellg() != -1)
			return false;
	}
	CharConverter::convert(d);
	IntConverter::convert(d);
	FloatConverter::convert(d);
	DoubleConverter::convert(d);
	return true;
}

void ScalarConverter::convert(const std::string& literal)
{
	std::stringstream ss;

	if (ifCharThenConvert(literal) == true)
		return ;
	if (ifIntThenConvert(literal) == true)
		return ;
	if (ifFloatThenConvert(literal) == true)
		return ;
	if (ifDoubleThenConvert(literal) == true)
		return ;
	std::cout << "There is no valid conversion...\n";
	return ;
}
