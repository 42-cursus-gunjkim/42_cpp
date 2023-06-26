#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point &p);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

	Point &operator=(const Point &p);

	static Fixed crossProduct(const Point &a, const Point &b);
};

bool operator==(const Point &a, const Point &b);
bool operator!=(const Point &a, const Point &b);
Point operator-(const Point &a, const Point &b);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif