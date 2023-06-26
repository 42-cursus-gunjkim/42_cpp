#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point &p) : x(p.x), y(p.y) {}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

Point &Point::operator=(const Point &p) {
	if (this != &p) {
		const_cast<Fixed &>(this->x) = p.x;
		const_cast<Fixed &>(this->y) = p.y;	
	}
	return *this;
}

Fixed Point::crossProduct(const Point &a, const Point &b) {
	return (a.getX() * b.getY() - a.getY() * b.getX());
}

bool operator==(const Point &a, const Point &b) {
	return (a.getX() == b.getX() && a.getY() == b.getY());
}

bool operator!=(const Point &a, const Point &b) {
	return !(a == b);
}

Point operator-(const Point &a, const Point &b) {
	return Point(a.getX() - b.getX(), a.getY() - b.getY());
}
