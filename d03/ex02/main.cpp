#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
	//
	std::cout << "----- Test's for ScavTrap ------" << std::endl;

	ScavTrap			trappy("Handsome Jack");

	trappy.rangedAttack("K!LL3R");
	trappy.rangedAttack("Something");
	// more
	std::cout << trappy;
	std::cout << "Doing takeDamage for 10HP, should take 3HP LESS" << std::endl;
	trappy.takeDamage(10); // should take 3 less.
	std::cout << trappy;
}
