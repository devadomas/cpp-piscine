#include <iostream>
#include "span.hpp"

int		main(void)
{
	Span sp = Span(1);

	try
	{
		std::cout << "Adding number 1" << std::endl;
		sp.addNumber(1);
		std::cout << "Adding number 2 <- should throw exception because Span is full" << std::endl;
		sp.addNumber(2);
	}
	catch (std::exception & e)
	{
		std::cerr << "Cought error while adding numbers: " << e.what() << std::endl;
	}

	Span newSp = Span(5);

	newSp.addNumber(5);
	newSp.addNumber(3);
	newSp.addNumber(17);
	newSp.addNumber(9);
	newSp.addNumber(11);

	std::cout << newSp.shortestSpan() << std::endl;
	std::cout << newSp.longestSpan() << std::endl;
}
