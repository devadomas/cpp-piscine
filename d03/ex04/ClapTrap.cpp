#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) // it's protected so should not be called
{
	std::cout << "ClapTrap default(empty) constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(
	std::string const & name,
	int					valueHit,
	int					maxHit,
	int					energyPoints,
	int					maxEnergyPoints,
	int					level,
	int					meleeDamage,
	int					rangedAttack,
	int					armor,
	std::string const &	type
):	_name(name), _valueHit(valueHit), _maxHit(maxHit), _energyPoints(energyPoints),
	_maxEnergyPoints(maxEnergyPoints), _level(level), _meleeDamage(meleeDamage),
	_rangedAttack(rangedAttack), _armor(armor), _type(type)
{
	std::cout << "ClapTrap constructor has been called name: " << name << " and type: " << type << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
}

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
		this->_maxHit = src._maxHit;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
		this->_type = src._type;
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
std::string		ClapTrap::getType(void) const { return this->_type; }

void			ClapTrap::setHP(int value) { this->_valueHit = value; }
void			ClapTrap::setEnergyPoints(int value) { this->_energyPoints = value; }
void			ClapTrap::setName(std::string const & name) { this->_name = name; }
void			ClapTrap::setMaxHP(int value) { this->_maxHit = value; }
void			ClapTrap::setMaxEnergyPoints(int value) { this->_maxEnergyPoints = value; }
void			ClapTrap::setLevel(int value) { this->_level = value; }
void			ClapTrap::setMeleeDamage(int value) { this->_meleeDamage = value; }
void			ClapTrap::setRangedAttack(int value) { this->_rangedAttack = value; }
void			ClapTrap::setArmour(int value) { this->_armor = value; }
void			ClapTrap::setType(std::string const & type) { this->_type = type; }

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_type << " " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage !" << std::endl;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_type << " " << this->_name << " attacks " << target << " at meelee attack, causing " << this->_meleeDamage << " points of damage !" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_valueHit == 0)
	{
		std::cout << this->_type << " " << this->_name << " is already done for today... Stop killing dead robot, YOU SADIST!" << std::endl;
		return ;
	}
	if (this->_armor >= int(amount))
	{
		std::cout << this->_type << " " << this->_name << ": My armour is though enough! YOU HAVE NO POWER HERE MUAHAHAH" << std::endl;
		return ;
	}
	amount -= this->_armor;
	this->_valueHit -= amount;
	if (this->_valueHit <= 0)
	{
		this->_valueHit = 0;
		std::cout << this->_type << " " << this->_name << ": the hero has fallen..." << std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	this->_valueHit += amount;
	if (this->_valueHit > this->_maxHit)
	{
		this->_valueHit = this->_maxHit;
		std::cout << this->_type << " " << this->_name << ": I'm fully charged! Never been this ready!" << std::endl;
		return ;
	}
	std::cout << this->_type << " " << this->_name << ": Oh yeah! Ready to party! (Current hp: " << this->_valueHit << ")" << std::endl;
}

std::ostream & 	operator<<(std::ostream & o, ClapTrap const & frag)
{
	o << frag.getType() << " " << frag.getName() << " stats:" << std::endl
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
