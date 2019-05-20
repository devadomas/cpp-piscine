#include <iostream>
#include <ctime>
#include "ZombieHorde.hpp"


int				main(void)
{
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
