#pragma once

#include <iostream>
#include <climits>
#include <cmath>

class CharConverter
{
public:
	static void convert(char c);
	static void convert(long l);
	static void convert(float f);
	static void convert(double d);

private:
	CharConverter();
	CharConverter(const CharConverter& other);
	CharConverter& operator=(const CharConverter& other);
	~CharConverter();
};