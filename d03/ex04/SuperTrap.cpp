#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	std::cout << "SuperTrap useless constructor that will never be called" << std::endl;
}

SuperTrap::SuperTrap(std::string const & name):
	ClapTrap(
		name,
		this->defaultHitPoints,
		this->defaultMaxHitPoints,
		this->defaultEnergyPoints,
		this->defaultMaxEnergyPoints,
		1,
		this->defaultMeleeAttack,
		this->defaultRangedAttack,
		this->defaultArmour,
		"5UP4-3G0-TP"
)
{
	std::cout << "Constructor for SuperTrap called!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "Destrusctor for SuperTrap called!" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	*this = src;
}

SuperTrap &			SuperTrap::operator=(SuperTrap const & src)
{
	std::cout << "SuperTrap equal operator called" << std::endl;
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
