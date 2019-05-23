#include <iostream>
#include "SuperTrap.hpp"

int		main(void)
{
	std::cout << "------------------ Beggining of main  ------------------" << std::endl;

	FragTrap	claptrap("Keren");

	claptrap.rangedAttack("John");
	claptrap.meleeAttack("John");
	claptrap.takeDamage(10);
	claptrap.beRepaired(25);
	claptrap.meleeAttack("S0M!T");
	SuperTrap	newTrap("Wick");
	std::cout << "Proofing that assignation worked: " << newTrap.getName() << std::endl;
	std::cout << claptrap;

	std::cout << "------------------------" << std::endl;

	SuperTrap		*someTrap = new SuperTrap("R0B0T");
	someTrap->vaulthunter_dot_exe("KYBORG");
	someTrap->ninjaShoebox(claptrap);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	someTrap->takeDamage(20);
	std::cout << "Test of damage repair to full" << std::endl;
	someTrap->beRepaired(500);
	std::cout << *someTrap;

	std::cout << "---------------- END OF TESTS MAIN ---------------- " << std::endl;
}
