#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int n) {
	this->fixedPointValue = n << fractionalBits;
}

Fixed::Fixed(const float n) {
	this->fixedPointValue = static_cast<int>(roundf(n * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& f) {
	*this = f;
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
	return static_cast<int>(roundf(toFloat()));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a <= b) ? a : b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() <= b.getRawBits()) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a >= b) ? a : b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() >= b.getRawBits()) ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
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

Fixed Fixed::operator+(const Fixed &f) {
	Fixed result;

	result.setRawBits(this->getRawBits() + f.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &f) {
	Fixed result;

	result.setRawBits(this->getRawBits() - f.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &f) {
	Fixed result;

	result.setRawBits(static_cast<int>((this->toFloat() * f.toFloat()) *(1 << Fixed::fractionalBits)));
	return result;
}

Fixed Fixed::operator/(const Fixed &f) {
	Fixed result;

	result.setRawBits(static_cast<int>(roundf((this->getRawBits() / f.getRawBits()) * ( 1 << Fixed::fractionalBits))));
	return result;
}

bool Fixed::operator>(const Fixed &f) {
	return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) {
	return this->getRawBits() < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) {
	return this->getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) {
	return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) {
	return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) {
	return this->getRawBits() != f.getRawBits();
}

