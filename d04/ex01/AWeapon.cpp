#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
	_name(name), _valueAP(apcost), _damage(damage) {}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::AWeapon(void) {}
AWeapon::~AWeapon(void) {}

AWeapon &				AWeapon::operator=(AWeapon const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_valueAP = src.getAPCost();
		this->_damage = src.getDamage();
	}
	return *this;
}

std::string				AWeapon::getName(void) const
{
	return this->_name;
}

int						AWeapon::getAPCost(void) const
{
	return this->_valueAP;
}

int						AWeapon::getDamage(void) const
{
	return this->_damage;
}

bool					AWeapon::setName(std::string const & name)
{
	if (name.length() == 0)
		return false;
	this->_name = name;
	return true;
}

void					AWeapon::setAPCost(int cost)
{
	this->_valueAP = cost;
}

void					AWeapon::setDamage(int damage)
{
	this->_damage = damage;
}
