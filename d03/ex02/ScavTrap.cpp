#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const & name): _name(name)
{
	this->_valueHit = 100;
	this->_maxHit = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeDamage = 20;
	this->_rangedAttack = 15;
	this->_armor = 3;
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
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

void				ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage ! Bullets are dumb." << std::endl;
}

void				ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at meelee attack, causing " << this->_meleeDamage << " points of damage ! Take that!" << std::endl;
}

void				ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)amount - this->_armor < 0)
		return ;
	amount -= this->_armor;
	this->_valueHit -= amount;
	if (this->_valueHit < 0)
		this->_valueHit = 0;
}

void				ScavTrap::beRepaired(unsigned int amount)
{
	this->_energyPoints += amount;
	if (this->_energyPoints > this->_maxEnergyPoints)
		this->_energyPoints = this->_maxEnergyPoints;
}

int				ScavTrap::getHP(void) const
{
	return this->_valueHit;
}

int				ScavTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

std::string		ScavTrap::getName(void) const
{
	return this->_name;
}

std::ostream & 	operator<<(std::ostream & o, ScavTrap const & scav)
{
	o << "SC4V-TP " << scav.getName() << " status -> " <<
		"Hit:" << scav.getHP() << ";"
		"EnergyPoints:" << scav.getEnergyPoints() << std::endl;
	return o;
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
