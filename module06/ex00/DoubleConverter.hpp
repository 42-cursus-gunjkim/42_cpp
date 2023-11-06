#pragma once

#include <iostream>
#include <climits>

class DoubleConverter
{
public:
	static void convert(char c);
	static void convert(int i);
	static void convert(float f);
	static void convert(double d);

private:
	DoubleConverter() {}
	//IntConverter(const IntConverter& ic) {};
	//IntConverter& operator=(const IntConverter& ic) {};
	~DoubleConverter() {}
};