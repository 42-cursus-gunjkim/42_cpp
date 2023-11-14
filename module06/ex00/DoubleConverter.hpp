#pragma once

#include <iostream>
#include <climits>

class DoubleConverter
{
public:
	static void convert(char c);
	static void convert(long l);
	static void convert(float f);
	static void convert(double d);

private:
	DoubleConverter();
	DoubleConverter(const DoubleConverter& other);
	DoubleConverter& operator=(const DoubleConverter& other);
	~DoubleConverter();
};