#include <iostream>
#include "Fixed.class.hpp"

int			main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	// -- my implemented tests
	std::cout << "--- TESTS of mine ---" << std::endl;
	std::cout << "Values: a(" << a << ") | b(" << b << ")" << std::endl;
	std::cout << "Eval: (a > b) == " << (a > b ? "yes" : "no") << std::endl;
	std::cout << "Eval: (a < b) == " << (a < b ? "yes" : "no") << std::endl;
	std::cout << "Eval: (a >= b) == " << (a >= b ? "yes" : "no") << std::endl;
	std::cout << "Eval: (a <= b) == " << (a <= b ? "yes" : "no") << std::endl;
	std::cout << "Eval: (a != b) == " << (a != b ? "yes" : "no") << std::endl;
	std::cout << "Eval: (a == b) == " << (a == b ? "yes" : "no") << std::endl;
	std::cout << "Arithmetics time!" << std::endl;
	std::cout << "Eval: (a - b) = " << Fixed(a - b) << std::endl;
	std::cout << "Eval: (a + b) = " << Fixed(a + b) << std::endl;
	std::cout << "Eval: (a * b) = " << Fixed(a * b) << std::endl;
	std::cout << "Eval: (a / b) = " << Fixed(a / b) << std::endl;
	return (0);
}
