#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	std::stringstream ss;
	char c;
	int i;
	float f;
	double d;

	ss.str(literal);
	int startPosition = ss.tellg();
	int status = CASE_CHAR;

	while (1)
	{
		switch(status)
		{
			case CASE_CHAR:
				ss >> c;
				break;
			case CASE_INT:
				ss >> i;
				break;
			case CASE_FLOAT:
				ss >> f;
				break;
			case CASE_DOUBLE:
				ss >> d;
				break;
			default:
				break;
		}
		if (ss.fail() == false || status == CASE_FAIL)
			break;
		ss.clear();
		ss.seekg(0);
		status++;
	}

	switch(status)
	{
		case CASE_CHAR:
			CharConverter::convert(c);
			IntConverter::convert(c);
			FloatConverter::convert(c);
			DoubleConverter::convert(c);
			break;
		case CASE_INT:
			CharConverter::convert(i);
			IntConverter::convert(i);
			FloatConverter::convert(i);
			DoubleConverter::convert(i);
			break;
		case CASE_FLOAT:
			CharConverter::convert(f);
			IntConverter::convert(f);
			FloatConverter::convert(f);
			DoubleConverter::convert(f);
			break;
		case CASE_DOUBLE:
			CharConverter::convert(d);
			IntConverter::convert(d);
			FloatConverter::convert(d);
			DoubleConverter::convert(d);
			break;
		default:
			std::cout << "There is no valid conversion...\n";
			break;
	}
}
