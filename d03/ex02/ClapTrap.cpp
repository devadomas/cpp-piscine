#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) { }

ClapTrap::ClapTrap(
	std::string const & name,
	int					valueHit,
	int					maxHit,
	int					energyPoints,
	int					maxEnergyPoints,
	int					level,
	int					meleeDamage,
	int					rangedAttack,
	int					armor
):	_name(name), _valueHit(valueHit), _maxHit(maxHit), _energyPoints(energyPoints),
	_maxEnergyPoints(maxEnergyPoints), _level(level), _meleeDamage(meleeDamage),
	_rangedAttack(rangedAttack), _armor(armor)
{ }

ClapTrap::~ClapTrap(void) { }

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
}

ClapTrap &		ClapTrap::operator=(ClapTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_valueHit = src._valueHit;
		this->_maxHit = src._valueHit;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

int				ClapTrap::getHP(void) const { return this->_valueHit; }
int				ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }
std::string		ClapTrap::getName(void) const { return this->_name; }
int				ClapTrap::getMaxHP(void) const { return this->_maxHit; }
int				ClapTrap::getMaxEnergyPoints(void) const { return this->_maxEnergyPoints; }
int				ClapTrap::getLevel(void) const { return this->_level; }
int				ClapTrap::getMeleeDamage(void) const { return this->_meleeDamage; }
int				ClapTrap::getRangedAttack(void) const { return this->_rangedAttack; }
int				ClapTrap::getArmour(void) const { return this->_armor; }

void			ClapTrap::setHP(int value) { this->_valueHit = value; }
void			ClapTrap::setEnergyPoints(int value) { this->_energyPoints = value; }
void			ClapTrap::setName(std::string const & name) { this->_name = name; }
void			ClapTrap::setMaxHP(int value) { this->_maxHit = value; }
void			ClapTrap::setMaxEnergyPoints(int value) { this->_maxEnergyPoints = value; }
void			ClapTrap::setLevel(int value) { this->_level = value; }
void			ClapTrap::setMeleeDamage(int value) { this->_meleeDamage = value; }
void			ClapTrap::setRangedAttack(int value) { this->_rangedAttack = value; }
void			ClapTrap::setArmour(int value) { this->_armor = value; }


void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage !" << std::endl;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at meelee attack, causing " << this->_meleeDamage << " points of damage !" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_valueHit == 0)
	{
		std::cout << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_armor >= (int)amount)
	{
		std::cout << this->_name << " has an armour! You have no power with damage that low!!!" << std::endl;
		return ;
	}
	amount -= this->_armor;
	this->_valueHit -= amount;
	if (this->_valueHit <= 0)
	{
		this->_valueHit = 0;
		std::cout << "This amount of damage killed " << this->_name << "..." << std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	this->_valueHit += amount;
	if (this->_valueHit > this->_maxHit)
	{
		this->_energyPoints = this->_maxHit;
		std::cout << this->_name << " is now on full health mode!" << std::endl;
	}
}

std::ostream & 	operator<<(std::ostream & o, ClapTrap const & clap)
{
	o << clap.getName() << " has stats of: " << std::endl
		<< "HP: " << clap.getHP() << std::endl
		<< "Max HP: " << clap.getMaxHP() << std::endl
		<< "Energy Points: " << clap.getEnergyPoints() << std::endl
		<< "max Energy Points: " << clap.getMaxEnergyPoints() << std::endl
		<< "level: " << clap.getLevel() << std::endl
		<< "melee Damage: " << clap.getMeleeDamage() << std::endl
		<< "ranged Attack Damage: " << clap.getRangedAttack() << std::endl
		<< "armour: " << clap.getArmour() << std::endl;
	return o;
}
