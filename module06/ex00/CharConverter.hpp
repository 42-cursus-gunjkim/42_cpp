#pragma once

#include <iostream>
#include <climits>

class CharConverter
{
public:
	static void convert(char c);
	static void convert(int i);
	static void convert(float f);
	static void convert(double d);

private:
	CharConverter() {}
	//CharConverter(const CharConverter& cc) {};
	//CharConverter& operator=(const CharConverter& cc) {};
	~CharConverter() {}
};