#include <iostream>
#include <ctime>
#include "ZombieHorde.hpp"


int				main(void)
{
	/*
		Went little bit fancier and tried out throw/try/catch!
		For catching Exception error and preventing segfault on negative number
		Could have used `unsigned int` but eehhh... This is fancier!
	*/
	try
	{
		ZombieHorde zHorde(10);
		zHorde.announce();
	}
	catch(const char* msg)
	{
		std::cout << "Error: " << msg << std::endl;
	}
}
