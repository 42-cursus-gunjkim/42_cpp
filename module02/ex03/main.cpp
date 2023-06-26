#include "Point.hpp"

int main() {
	Point a(0,0);
	Point b(2,0);
	Point c(1,2);

	std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << bsp(a, b, c, Point(0.5, 0.5)) << std::endl;
	std::cout << bsp(a, b, c, Point(3, 1)) << std::endl;
	std::cout << bsp(a, b, c, Point(1, 3)) << std::endl;
	std::cout << bsp(a, b, c, Point(2, 0)) << std::endl;
}