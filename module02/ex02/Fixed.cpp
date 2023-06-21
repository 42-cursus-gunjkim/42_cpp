#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int n) {
	this->fixedPointValue = n << fractionalBits;
}

Fixed::Fixed(const float n) {
	this->fixedPointValue = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& f) {
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f) {
	if (this != &f)
		this->fixedPointValue = f.getRawBits();
	return *this;
}

Fixed& Fixed::operator++() {
	this->fixedPointValue++;
	return *this;
}

Fixed& Fixed::operator--() {
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->fixedPointValue++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixedPointValue--;
	return tmp;
}


int Fixed::getRawBits() const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->fixedPointValue) / (1 << this->fractionalBits);
}

int Fixed::toInt() const {
	return roundf(toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a <= b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a >= b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}

Fixed operator+(const Fixed &a, const Fixed &b) {
	return Fixed(a.getRawBits() + b.getRawBits());
}

Fixed operator-(const Fixed &a, const Fixed &b) {
	return Fixed(a.getRawBits() - b.getRawBits());
}

bool operator>(const Fixed &a, const Fixed &b) {
	return a.getRawBits() > b.getRawBits();
}

bool operator<(const Fixed &a, const Fixed &b) {
	return a.getRawBits() < b.getRawBits();
}

bool operator>=(const Fixed &a, const Fixed &b) {
	return a.getRawBits() >= b.getRawBits();
}

bool operator<=(const Fixed &a, const Fixed &b) {
	return a.getRawBits() <= b.getRawBits();
}

bool operator==(const Fixed &a, const Fixed &b) {
	return a.getRawBits() == b.getRawBits();
}

bool operator!=(const Fixed &a, const Fixed &b) {
	return a.getRawBits() != b.getRawBits();
}

