#include <iostream>
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap			*trap = new FragTrap("K!LL3R");

	trap->rangedAttack("Zer0");
	//
	trap->meleeAttack("Betty");
	trap->rangedAttack("Nelly");
	std::cout << *trap;
	// next!
	trap->takeDamage(200);
	std::cout << *trap;
	trap->beRepaired(500);
	trap->takeDamage(1);
	std::cout << *trap;
	trap->vaulthunter_dot_exe("Terminator");
	trap->vaulthunter_dot_exe("Norminattor");
	trap->vaulthunter_dot_exe("Verificator");
	trap->vaulthunter_dot_exe("Terminator");
	trap->vaulthunter_dot_exe("Norminattor");
	trap->vaulthunter_dot_exe("Verificator");
	std::cout << *trap;
	delete trap;
}
