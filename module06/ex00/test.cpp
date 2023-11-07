
#include <string>
#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;

	ss.str("2147483648");
	std::cout << ss.tellg() << std::endl;
	char i;
	ss >> i;
	std::cout << i << " " << ss.fail() << " " << ss.tellg() << std::endl;
	ss.clear();
	ss.seekg(0);
	double d;
	ss >> d;
	std::cout << d << " " << ss.fail() << " " << ss.tellg() << std::endl;
}