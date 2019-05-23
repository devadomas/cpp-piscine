#include "NinjaTrap.hpp"

int	NinjaTrap::defaultEnergyPoints = 120;
int	NinjaTrap::defaultMaxEnergyPoints = 120;
int	NinjaTrap::defaultMeleeAttack = 60;

NinjaTrap::NinjaTrap(void) {}

NinjaTrap::NinjaTrap(std::string const & name):
	ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "INAC " << name << " appeared! Give us open ports for remote access or give us death!" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "INAC " << this->_name << "has been destroyed... MurderDeathKill! Annihilate! Extermin-" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
}

NinjaTrap &			NinjaTrap::operator=(NinjaTrap const & src)
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

void				NinjaTrap::ninjaShoebox(ClapTrap const & src)
{
	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << src.getName() << " with a ultimate fist punch!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(FragTrap const & src)
{
	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << src.getName() << " with a Pincer Attack!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(ScavTrap const & src)
{
	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << src.getName() << " with a Viva La Robolution Attack!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(NinjaTrap const & src)
{
	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << src.getName() << " with a Shoryuken Attack!" << std::endl;
	}
}

void				NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at meelee attack(from NinjaTrap class), causing " << this->_meleeDamage << " points of damage !" << std::endl;
}
