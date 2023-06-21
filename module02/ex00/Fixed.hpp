#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

private:
	int	fixedPointValue;
	static const int	fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif