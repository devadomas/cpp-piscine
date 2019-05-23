#include <iostream>
#include "Fixed.class.hpp"
#include "Vector.class.hpp"
#include "Solver.class.hpp"

int		main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "eval_expr: usage: ./eval_expr [expression]" << std::endl;
		return 1;
	}

	Solver		rpn(argv[1]);
	rpn.tokenize();
	if (!rpn.verify())
	{
		std::cerr << "Invalid input." << std::endl;
		return 1;
	}
	rpn.format();
	std::cout << rpn.solve() << std::endl;
	return 0;
}
