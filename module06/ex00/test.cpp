
#include <string>
#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;

	ss.str("2147483648.0f");
	std::cout << ss.tellg() << std::endl;
	float d;
	ss >> d;
	std::cout << d << " " << ss.fail() << " " << ss.tellg() << std::endl;
}