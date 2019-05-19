#include <iostream>
# include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon &weapon): _name(name), _weapon(weapon)
{

}
HumanA::~HumanA(void)
{

}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
