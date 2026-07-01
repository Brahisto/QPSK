//Complex.cpp
#include "Complex.h"

Complex::Complex(double re = 0, double im = 0) {
	real = re;
	imag = im;
}

Complex::Complex(int n) {
	real = n;
	imag = n;
}

Complex::Complex() : real(0), imag(0) {};

double Complex::module() const {
	double abs_ = std::sqrt(pow(real, 2) + pow(imag, 2));
	return abs_;
}
void Complex::phase() const {
	float phase;
	if (real != 0.0) phase = std::atan(imag / real);
	else (imag > 0 ? phase = PI / 2 : phase = -PI / 2);
	std::cout << "phase = " << phase << std::endl;
}
Complex Complex::operator+(const Complex& num1) const {
	Complex res{ 0., 0. };
	res.real = this->real + num1.real;
	res.imag = this->imag + num1.imag;
	return res;
}
Complex Complex::operator-(const Complex& num1) const {
	Complex res{ 0., 0. };
	res.real = this->real - num1.real;
	res.imag = this->imag - num1.imag;
	return res;
}
Complex Complex::operator*(const Complex& num1) const {
	Complex res{ 0., 0. };
	double a, b, c, d;
	a = this->real; b = this->imag; c = num1.real; d = num1.imag;
	res.real = a * c - b * d;
	res.imag = a * d + b * c;
	return res;
}
std::ostream & out(std::ostream & os, const Complex & num) {
	os << "real = " << num.real << "; imag = " << num.imag << std::endl;
    return os; 
}