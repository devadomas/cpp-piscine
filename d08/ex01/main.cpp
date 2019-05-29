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
}
