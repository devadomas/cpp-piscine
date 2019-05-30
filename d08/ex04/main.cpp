#include <iostream>
#include "Fixed.class.hpp"
#include "Solver.class.hpp"

int		main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "ex04: usage: ./ex04 [expression]" << std::endl;
		return 1;
	}

	Solver		rpn(argv[1]);
	rpn.tokenize();

	if (!rpn.verify())
	{
		std::cerr << "Invalid input." << std::endl;
		return 1;
	}
	rpn.printTokens();
	rpn.format();
	rpn.printRPN();
	rpn.solve();

	std::cout << "Result : " << rpn.result() << std::endl;
	return 0;
}
