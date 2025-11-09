#include "header.h"


Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::modul() const {
    return std::sqrt(real * real + imag * imag);
}

double Complex::argument() const {
    return std::atan2(imag, real);
}

Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        real = rhs.real;
        imag = rhs.imag;
    }
    return *this;
}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::operator+(int num) {
    return Complex(real + num, imag);
}

Complex operator+(int num, const Complex& rhs) {
    return Complex(num + rhs.real, rhs.imag);
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++real;
    return temp;
}

Complex& Complex::operator+=(int num) {
    real += num;
    return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
    *this = *this + rhs;
    return *this;
}

Complex Complex::operator-(const Complex& rhs) const {
    return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator-(int num) {
    return *this + (-num);
}

Complex operator-(int num, const Complex& rhs) {
    return Complex(num - rhs.real, rhs.imag);
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --real;
    return temp;
}

Complex& Complex::operator-=(int num) {
    real -= num;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    *this = *this - rhs;
    return *this;
}

Complex Complex::operator*(const Complex& rhs) const {
    return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
}

Complex Complex::operator/(const Complex& rhs) const {
    double denom = rhs.real * rhs.real + rhs.imag * rhs.imag;
    if (denom == 0) {
        throw "denum is zero\n";
    }
    return Complex((real * rhs.real + imag * rhs.imag) / denom,
        (imag * rhs.real - real * rhs.imag) / denom);
}

Complex Complex::sqrtComplex(int k) const {
    const double PI = acos(-1);
    double sqrtMod = sqrt(modul());
    double arg = argument();

    double newreal = sqrtMod * cos((arg + 2 * PI * k) / 2);
    double newimag = sqrtMod * sin((arg + 2 * PI * k) / 2);

    return Complex(newreal, newimag);
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
    if (rhs.imag == 0) {
        os << rhs.real << '\n';
    }
    else if (std::abs(rhs.imag) == 1) {
        os << rhs.real << (rhs.imag == 1 ? " + " : " - ") << "i\n";
    }
    else {
        os << rhs.real << (rhs.imag >= 0 ? " + " : " - ") << std::abs(rhs.imag) << "i\n";
    }
    return os;
}

Complex::~Complex() {}