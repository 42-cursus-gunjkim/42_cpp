#pragma once

#include <iostream>
#include <climits>
#include <iomanip>

class FloatConverter
{
public:
	static void convert(char c);
	static void convert(long l);
	static void convert(float f);
	static void convert(double d);

private:
	FloatConverter();
	FloatConverter(const FloatConverter& other);
	FloatConverter& operator=(const FloatConverter& other);
	~FloatConverter();
};