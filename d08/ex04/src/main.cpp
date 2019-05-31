#include <iostream>
#include "Solver.class.hpp"

int		main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "ex04: usage: ./ex04 [expression]" << std::endl;
		return 1;
	}
	try {
		Solver		rpn(argv[1]);

		rpn.tokenize();
		rpn.verify();
		rpn.printTokens();
		rpn.format();
		rpn.printRPN();
		rpn.solve();
		rpn.printCommands();
		std::cout << "Result : " << rpn.result() << std::endl;
	}
	catch(Solver::InvalidInputException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << "Error! Stay within INT limits!" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Cought exception: " << e.what() << std::endl;
	}
	return 0;
}
