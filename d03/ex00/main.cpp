#include <iostream>
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	claptrap("Keren");

	std::srand(std::time(nullptr)); // for rand() to work
	claptrap.rangedAttack("Zer0");
	// Taking damage test
	std::cout << "Taking damage with a value of 10" << std::endl;
	claptrap.takeDamage(10);
	std::cout << "Try out the special attack!" << std::endl;
	claptrap.vaulthunter_dot_exe("John");
	claptrap.vaulthunter_dot_exe("John");
	claptrap.vaulthunter_dot_exe("John");
	claptrap.vaulthunter_dot_exe("John");
	claptrap.vaulthunter_dot_exe("John");
	//
	claptrap.beRepaired(300);
	std::cout << claptrap; // for logging purposes

}
