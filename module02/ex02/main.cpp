#include "Fixed.hpp"

int main() {
	Fixed a(5.123f);
	Fixed b(2.123f);
	std::cout << a << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a++ << std::endl;
	std::cout << ++a << std::endl;
}