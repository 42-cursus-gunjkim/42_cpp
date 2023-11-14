#pragma once

#include <iostream>
#include <climits>
#include <cmath>

class IntConverter
{
public:
	static void convert(char c);
	static void convert(long l);
	static void convert(float f);
	static void convert(double d);

private:
	IntConverter();
	IntConverter(const IntConverter& other);
	IntConverter& operator=(const IntConverter& other);
	~IntConverter();
};