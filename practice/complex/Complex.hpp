#include <iostream>

class Complex
{
private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c);

	Complex &operator=(const Complex& c);
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	Complex &operator+=(const Complex& c);
	Complex &operator-=(const Complex& c);
	Complex &operator*=(const Complex& c);
	Complex &operator/=(const Complex& c);

	void println();
};
