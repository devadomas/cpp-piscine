#include "Weapon.hpp"

Weapon::Weapon(std::string const type): _type(type)
{

}

Weapon::~Weapon(void)
{

}

std::string		Weapon::getType(void) const
{
	return (this->_type);
}

bool			Weapon::setType(std::string const type)
{
	if (type.length() == 0)
		return (false);
	this->_type = type;
	return (true);
}
