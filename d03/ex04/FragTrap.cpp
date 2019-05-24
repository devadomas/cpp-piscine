#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) { }

int	FragTrap::defaultHitPoints = 100;
int	FragTrap::defaultMaxHitPoints = 100;
int	FragTrap::defaultRangedAttack = 20;
int	FragTrap::defaultArmour = 5;

FragTrap::FragTrap(std::string const & name):
	ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::srand(std::time(nullptr)); // for true rand()
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
		this->_maxEnergyPoints = src._maxEnergyPoints;
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
	std::string		fight = attacks[rand() % 6];

	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;
	std::cout << "FR4G-TP " << this->_name << ": uses a special attack " << fight << " on target " << target << " and humiliates it!!!" << std::endl;
}

std::ostream & 		operator<<(std::ostream & o, FragTrap const & clap)
{
	o << "FR4G-TP " << clap.getName() << " has stats of: " << std::endl
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

void				FragTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttack << " points of damage! -- Called from FragTrap!" << std::endl;
}
