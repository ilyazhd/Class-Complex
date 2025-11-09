#include "header.h"


int main() {

	Complex num1(1, 2);
	Complex num2(3, -2);
	num1 += num2;
	num1 = num2;
	Complex sqrt1 = num1.sqrtComplex(1);
	Complex sqrt2 = num1.sqrtComplex(2);
	std::cout << sqrt1 << sqrt2;
	std::cout << num1;
	std::cout << num1.modul() << '\n';
	std::cout << ++num1;
	std::cout << --num1;
	std::cout << num1 * num2;
	std::cout << num1 / num2;
	std::cout << num1 + num2;

		

	return 0;
}