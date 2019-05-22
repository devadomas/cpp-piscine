#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "FR4G-TP " << name << " appeared! Protect humanity!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->_name << " has been destroyed... Have a lovely afternoon, and thank you for using Hyperion Robot Services." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap &			FragTrap::operator=(FragTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_valueHit = src._valueHit;
		this->_maxHit = src._maxHit;
		this->_energyPoints = src._energyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

void				FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		attacks[] = {
		"Torgue Fiesta",
		"Pirate Ship Mode",
		"Clap-in-the-Box",
		"Gun Wizard",
		"One-Shot Wonder",
		"Laser Inferno"
	};

	if (this->_energyPoints < 25)
		std::cout << "FR4G-TP " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "FR4G-TP " << this->_name << ": uses a special attack " << attacks[rand() % 6] << " on target " << target << " and humiliates it!!!" << std::endl;
	}
}

std::ostream & 	operator<<(std::ostream & o, FragTrap const & frag)
{
	o << "FR4G-TP " << frag.getName() << " status -> " <<
		"Hit:" << frag.getHP() << ";"
		"EnergyPoints:" << frag.getEnergyPoints() << std::endl;
	return o;
}
