#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	claptrap("Keren");
	ScavTrap	robot("K1ller");

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
	// ScavTrap class testing
	std::cout << robot;
	robot.takeDamage(10); // should take 3 less
	std::cout << robot;
	robot.challengeNewcomer("Lucky");
	std::cout << robot;
}
