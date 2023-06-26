#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point ab = b - a;
	Point bc = c - b;
	Point ca = a - c;

	Fixed c1 = Point::crossProduct(ab, point - a);
	Fixed c2 = Point::crossProduct(bc, point - b);
	Fixed c3 = Point::crossProduct(ca, point - c);

	if ((c1 < 0 && c2 < 0 && c3 < 0) || (c1 > 0 && c2 > 0 && c3 > 0))
		return true;
	return false;
}