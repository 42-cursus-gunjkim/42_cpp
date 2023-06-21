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

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif