#pragma once

#include <iostream>
#include <climits>

class IntConverter
{
public:
	static void convert(char c);
	static void convert(int i);
	static void convert(float f);
	static void convert(double d);

private:
	IntConverter() {}
	//IntConverter(const IntConverter& ic) {};
	//IntConverter& operator=(const IntConverter& ic) {};
	~IntConverter() {}
};