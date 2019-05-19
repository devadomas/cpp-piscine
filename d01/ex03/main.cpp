#include <iostream>
#include <ctime>
#include "ZombieHorde.hpp"


int				main(void)
{
	std::srand(std::time(nullptr));
	try
	{
		ZombieHorde zHorde(-100);
	}
	catch(const char* msg)
	{
		std::cout << "Error: " << msg << std::endl;
	}
}
