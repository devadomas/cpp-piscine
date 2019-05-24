#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) { } // private default constructor for future

ScavTrap::ScavTrap(std::string const & name): _name(name)
{
	std::srand(std::time(nullptr)); // for true rand()
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
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

//		Getters
int					ScavTrap::getHP(void) const { return this->_valueHit; }
int					ScavTrap::getEnergyPoints(void) const { return this->_energyPoints; }
std::string			ScavTrap::getName(void) const { return this->_name; }
int					ScavTrap::getMaxHP(void) const { return this->_maxHit; }
int					ScavTrap::getMaxEnergyPoints(void) const { return this->_maxEnergyPoints; }
int					ScavTrap::getLevel(void) const { return this->_level; }
int					ScavTrap::getMeleeDamage(void) const { return this->_meleeDamage; }
int					ScavTrap::getRangedAttack(void) const { return this->_rangedAttack; }
int					ScavTrap::getArmour(void) const { return this->_armor; }

// Attacks&stuff
void				ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage !" << std::endl;
}

void				ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at meelee attack, causing " << this->_meleeDamage << " points of damage !" << std::endl;
}

void				ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_valueHit == 0)
	{
		std::cout << "SC4V-TP " << this->_name << " is already done for today... Stop killing dead robot, YOU SADIST!" << std::endl;
		return ;
	}
	if (this->_armor > int(amount))
	{
		std::cout << "SC4V-TP " << this->_name << ": My armour is though enough! YOU HAVE NO POWER HERE MUAHAHAH" << std::endl;
		return ;
	}
	amount -= this->_armor;
	this->_valueHit -= amount;
	if (this->_valueHit <= 0)
	{
		this->_valueHit = 0;
		std::cout << "SC4V-TP " << this->_name << ": the hero has fallen..." << std::endl;
	}
}

void				ScavTrap::beRepaired(unsigned int amount)
{
	this->_valueHit += amount;
	if (this->_valueHit > this->_maxHit)
	{
		this->_valueHit = this->_maxHit;
		std::cout << "SC4V-TP " << this->_name << ": I'm fully charged! Never been this ready!" << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << ": Oh yeah! Ready to party! (Current hp: " << this->_valueHit << ")" << std::endl;
}

std::ostream & 	operator<<(std::ostream & o, ScavTrap const & frag)
{
	o << "SC4V-TP " << frag.getName() << " stats:" << std::endl
		<< "- HP: " << frag.getHP() << std::endl
		<< "- maxHP: " << frag.getMaxHP() << std::endl
		<< "- EnergyPoints: " << frag.getEnergyPoints() << std::endl
		<< "- max EnergyPoints: " << frag.getMaxEnergyPoints() << std::endl
		<< "- level: " << frag.getLevel() << std::endl
		<< "- melee DMG: " << frag.getMeleeDamage() << std::endl
		<< "- ranged DMG: " << frag.getRangedAttack() << std::endl
		<< "- Armour: " << frag.getArmour() << std::endl;
	return o;
}

// special

void				ScavTrap::challengeNewcomer(std::string const & target)
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
