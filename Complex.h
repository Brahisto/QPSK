//Complex.h
#pragma once

#include <iostream>
#include <cmath>
constexpr double PI = 3.14159;


class Complex {
public:
    double real;
	double imag;
	Complex();
	Complex(int);
	Complex(double, double);
	double module() const;
	void phase() const;
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
    friend std::ostream & out(std::ostream &, const Complex &);
	
};



