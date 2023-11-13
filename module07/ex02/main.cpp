#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> intArr(10);
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	
	for (int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << std::endl;

	try
	{
		int a = intArr[-1];
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "Who are you?";
	strArr[2] = "What is your name?";

	for (int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;
}