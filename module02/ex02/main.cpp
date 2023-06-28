#include "Fixed.hpp"

int main() {
	Fixed a(127.0f);
	Fixed const b(256.0f);

	std::cout << sizeof(int) << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}