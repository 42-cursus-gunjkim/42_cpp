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
	static const int CASE_CHAR = 0;
	static const int CASE_INT = 1;
	static const int CASE_FLOAT = 2;
	static const int CASE_DOUBLE = 3;
	static const int CASE_FAIL = 4;
};