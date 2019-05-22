#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type): _type(type), _name(name)
{
	// nothing needed
}

Zombie::~Zombie(void)
{
	// baaah DEAD
}

void		Zombie::announce() const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

bool		Zombie::setName(std::string const name)
{
	if (name.length() == 0)
		return false;
	this->_name = name;
	return true;
}

bool		Zombie::setType(std::string const type)
{
	if (type.length() == 0)
		return false;
	this->_type = type;
	return true;
}

std::string	Zombie::getName(void) const
{
	return this->_name;
}

std::string	Zombie::getType(void) const
{
	return this->_type;
}
