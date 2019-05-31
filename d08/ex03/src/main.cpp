#include "project.hpp"

int		main( int ac , char **av )
{
	if (ac != 2)
	{
		std::cerr << "No file passed" << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		MindOpen	mindOpen;

		mindOpen.parse(av[1]);
		mindOpen.execute();
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}
}
