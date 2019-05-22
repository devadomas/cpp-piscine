#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	claptrap("Keren");
	ScavTrap	robot("K1ller");

	claptrap.vaulthunter_dot_exe("John");
	robot.takeDamage(10); // should take 3 less

	std::cout << robot;
	// destructor..
}
