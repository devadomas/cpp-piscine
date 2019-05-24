#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const & name):
	ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::srand(std::time(nullptr)); // for true rand()
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
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDamage = src._meleeDamage;
		this->_rangedAttack = src._rangedAttack;
		this->_armor = src._armor;
	}
	return *this;
}

void				NinjaTrap::ninjaShoebox(ClapTrap const & enemy)
{
	std::string			arr[] = {
		"fist punch",
		"kick flip",
		"salto punch",
		"superman kick"
	};

	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make special attack!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << enemy.getName() << " with a ultimate " << arr[rand() % 4] << "!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(FragTrap const & enemy)
{
	std::string			arr[] = {
		"Iron Fist",
		"Heavy Handed attack",
		"Venom attack",
		"Lethal Strike"
	};

	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make " << arr[rand() % 4] << "!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << enemy.getName() << " with a " << arr[rand() % 4] << "!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(ScavTrap const & enemy)
{
	std::string			arr[] = {
		"Iron Fist",
		"Heavy Handed attack",
		"Venom attack",
		"Lethal Strike"
	};

	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make " << arr[rand() % 4] << "!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << enemy.getName() << " with a " << arr[rand() % 4] << "!" << std::endl;
	}
}

void				NinjaTrap::ninjaShoebox(NinjaTrap const & enemy)
{
	std::string			arr[] = {
		"Iron Fist",
		"Heavy Handed attack",
		"Venom attack",
		"Lethal Strike"
	};

	if (this->_energyPoints < 25)
		std::cout << "INAC " << this->_name << ": aaah crap! There is not enough energy to make " << arr[rand() % 4] << "!" << std::endl;
	else
	{
		this->_energyPoints -= 25;
		std::cout << "INAC " << this->_name << " attacks " << enemy.getName() << " with a " << arr[rand() % 4] << "!" << std::endl;
	}
}
