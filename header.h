#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cmath>


class Complex
{
private:
	double real;
	double imag;
public:
    Complex();
    Complex(double r, double i);

    double modul() const;
    double argument() const;

    Complex& operator=(const Complex& rhs);

    Complex operator+(const Complex& rhs) const;
    Complex operator+(int num);
    friend Complex operator+(int num, const Complex& rhs);

    Complex& operator++();
    Complex operator++(int);

    Complex& operator+=(int num);
    Complex& operator+=(const Complex& rhs);

    Complex operator-(const Complex& rhs) const;
    Complex operator-(int num);
    friend Complex operator-(int num, const Complex& rhs);

    Complex& operator--();
    Complex operator--(int);

    Complex& operator-=(int num);
    Complex& operator-=(const Complex& rhs);

    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;

    Complex sqrtComplex(int k) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);

    ~Complex();
};



#endif // !HEADER_H

