#include <iostream>
#include "SuperTrap.hpp"

int		main(void)
{
	SuperTrap	claptrap("Keren");

	claptrap.rangedAttack("John");
	claptrap.meleeAttack("John");
	std::cout << claptrap;
}
