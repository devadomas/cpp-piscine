#include <iostream>
#include "Character.hpp"

Character::Character(void) { }
Character::~Character(void) { }
Character::Character(std::string const & name): _name(name), _valueAP(40), _wpn(NULL) { }
Character::Character(Character const & src) { *this = src; }

Character &				Character::operator=(Character const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_valueAP = src.getAP();
		this->_wpn = src.getWeapon();
	}
	return *this;
}

void					Character::recoverAP(void)
{
	this->_valueAP += 10;
	if (this->_valueAP > 40)
		this->_valueAP = 40;
}

void					Character::equip(AWeapon *wpn) { this->_wpn = wpn; }
std::string				Character::getName(void) const { return this->_name; }
AWeapon *				Character::getWeapon(void) const { return this->_wpn; }
int						Character::getAP(void) const { return this->_valueAP; }

void					Character::attack(Enemy *enemy)
{
	if (this->_wpn == NULL || enemy == NULL)
		return ;
	if ((this->_valueAP - this->_wpn->getAPCost()) < 0)
		return ;
	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_wpn->getName() << std::endl;
	this->_valueAP -= this->_wpn->getAPCost();
	this->_wpn->attack();
	enemy->takeDamage(this->_wpn->getDamage());
	if (enemy->getHp() < 0)
	{
		delete enemy;
		enemy = NULL;
	}
}

std::ostream &			operator<<(std::ostream & o, Character const & chr)
{
	if (chr.getWeapon())
		o << chr.getName() << " has " << chr.getAP() << " AP and wields a " << chr.getWeapon()->getName() << std::endl;
	else
		o << chr.getName() << " has " << chr.getAP() << " AP and is unarmed" << std::endl;
	return o;
}
