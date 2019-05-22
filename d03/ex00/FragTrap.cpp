#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name): _name(name)
{
	this->_valueHit = 100;
	this->_maxHit = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeDamage = 30;
	this->_rangedAttack = 20;
	this->_armor = 5;
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

void				FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage !" << std::endl;
}

void				FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at meelee attack, causing " << this->_meleeDamage << " points of damage !" << std::endl;
}

void				FragTrap::takeDamage(unsigned int amount)
{
	if ((int)amount - this->_armor < 0)
		return ;
	amount -= this->_armor;
	this->_valueHit -= amount;
	if (this->_valueHit < 0)
		this->_valueHit = 0;
}

void				FragTrap::beRepaired(unsigned int amount)
{
	this->_valueHit += amount;
	if (this->_valueHit > this->_maxHit)
		this->_valueHit = this->_maxHit;
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
	{
		std::cout << "FR4G-TP " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;
	std::cout << "FR4G-TP " << this->_name << ": uses a special attack " << attacks[rand() % 6] << " on target " << target << " and humiliates it!!!" << std::endl;
}

int				FragTrap::getHP(void) const
{
	return this->_valueHit;
}

int				FragTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

std::string		FragTrap::getName(void) const
{
	return this->_name;
}

std::ostream & 	operator<<(std::ostream & o, FragTrap const & frag)
{
	o << "FR4G-TP " << frag.getName() << " status -> " <<
		"Hit:" << frag.getHP() << ";"
		"EnergyPoints:" << frag.getEnergyPoints() << std::endl;
	return o;
}
