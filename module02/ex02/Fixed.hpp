#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int	fixedPointValue;
	static const int	fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &f);

	Fixed &operator=(const Fixed &f);
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

Fixed operator+(const Fixed &a, const Fixed &b);
Fixed operator-(const Fixed &a, const Fixed &b);
//Fixed operator*(const Fixed &a, const Fixed &b);
//Fixed operator/(const Fixed &a, const Fixed &b);

bool operator>(const Fixed &a, const Fixed &b);
bool operator<(const Fixed &a, const Fixed &b);
bool operator>=(const Fixed &a, const Fixed &b);
bool operator<=(const Fixed &a, const Fixed &b);
bool operator==(const Fixed &a, const Fixed &b);
bool operator!=(const Fixed &a, const Fixed &b);

#endif