#include <iostream>
#include "Fixed.class.hpp"
#include "List.class.hpp"
#include "Solver.class.hpp"

/*
	Options for implamentation:
		- Binary tree: http://www.codinghelmet.com/exercises/expression-evaluator
		- Reverse polish notation
*/

int			main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "eval_expr: run it like ./eval_expr [expression]" << std::endl;
		return (1);
	}

	Solver		rpn(argv[1]);
	rpn.tokenize();
	// verification needed
	rpn.build();
	std::cout << rpn.solve() << std::endl;
	// std::cout << "Size: " << rpn.getTokens().getSize() << std::endl;
	return (0);
}
