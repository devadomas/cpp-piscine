#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) { }

ScavTrap::ScavTrap(std::string const & name):
	ClapTrap(name, 100, 100, 100, 50, 1, 20, 15, 3, "SC4V-TP")
{
	std::cout << "SC4V-TP " << name << " appeared!  I once started a revolution myself." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP " << this->_name << " has been destroyed... I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap &			ScavTrap::operator=(ScavTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_valueHit = src._valueHit;
		this->_maxHit = src._maxHit;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string			challenge[] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance battle! Or, you know... regular battle.",
		"Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"
	};
	if (this->_energyPoints < 25)
		std::cout << "SC4V-TP " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with: " << challenge[rand() % 5] << std::endl;
	}
}
