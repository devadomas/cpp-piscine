#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
	_name(name), _valueAP(apcost), _damage(damage) {}

AWeapon::AWeapon(void) { }
AWeapon::~AWeapon(void) { }
AWeapon::AWeapon(AWeapon const & src) { *this = src; }

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

std::string				AWeapon::getName(void) const { return this->_name; }
int						AWeapon::getAPCost(void) const { return this->_valueAP; }
int						AWeapon::getDamage(void) const { return this->_damage; }
void					AWeapon::setName(std::string const & name) { this->_name = name; }
void					AWeapon::setAPCost(int cost) { this->_valueAP = cost; }
void					AWeapon::setDamage(int damage) { this->_damage = damage; }
