#include <iostream>
#include "SuperTrap.hpp"

int		main(void)
{
	std::cout << "------------------ Beggining of main  ------------------" << std::endl;
	SuperTrap *			trap = new SuperTrap("SuperTrap");
	NinjaTrap			ninja("NinjaTrap");
	FragTrap			frag("FragTrap");
	std::cout << "------------------" << std::endl;
	std::cout << *trap;
	std::cout << "------------------" << std::endl;
	std::cout << ninja;
	std::cout << "------------------" << std::endl;
	std::cout << frag;
	// attacks
	std::cout << "------------------" << std::endl;
	trap->meleeAttack("Something");
	trap->rangedAttack("Someone");
	std::cout << "------------------" << std::endl;
	// random damages ant etc
	trap->takeDamage(50);
	std::cout << *trap;
	std::cout << "------------------ Beggining of main  ------------------" << std::endl;
	delete trap; // as always: no loose ends
}
