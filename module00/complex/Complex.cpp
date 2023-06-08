#include "Complex.hpp"

Complex::Complex(const Complex& c)
{
	real = c.real;
	img = c.img;
}

Complex &Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex Complex::operator+(const Complex& c) const
{
	Complex result(real + c.real, img + c.img);
	return result;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex result(real - c.real, img - c.img);
	return result;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex result(real * c.real - img * c.img, real * c.img + img * c.real);
	return result;
}

Complex Complex::operator/(const Complex& c) const
{
	Complex result(
    (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return result;
}

Complex &Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex &Complex::operator-=(const Complex& c)
{
	(*this) = (*this) - c;
	return *this;
}

Complex &Complex::operator*=(const Complex& c)
{
	(*this) = (*this) * c;
	return *this;
}

Complex &Complex::operator/=(const Complex& c)
{
	(*this) = (*this) / c;
	return *this;
}

void Complex::println()
{
	std::cout << "(" << real << " , " << img << " ) " << std::endl;
}