#pragma once

#include <sstream>
#include "CharConverter.hpp"
#include "IntConverter.hpp"
#include "FloatConverter.hpp"
#include "DoubleConverter.hpp"

class ScalarConverter
{
public:
	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};