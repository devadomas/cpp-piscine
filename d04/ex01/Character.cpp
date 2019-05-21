#include <iostream>
#include "Character.hpp"

Character::Character(std::string const & name): _name(name)
{
	this->_valueAP = 40;
	this->_wpn = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(void) { }

Character &				Character::operator=(Character const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_valueAP = src._valueAP;
		this->_wpn = src._wpn;
	}
	return *this;
}

void					Character::recoverAP(void)
{
	this->_valueAP += 10;
	if (this->_valueAP > 40)
		this->_valueAP = 40;
}

void					Character::equip(AWeapon *wpn)
{
	this->_wpn = wpn;
}

std::string				Character::getName(void) const
{
	return this->_name;
}

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
		delete enemy;
}

AWeapon *				Character::getWeapon(void) const
{
	return this->_wpn;
}

int						Character::getAP(void) const
{
	return this->_valueAP;
}

std::ostream &			operator<<(std::ostream & o, Character const & chr)
{
	if (chr.getWeapon())
		o << chr.getName() << " has " << chr.getAP() << " AP and wields a " << chr.getWeapon()->getName() << std::endl;
	else
		o << chr.getName() << " has " << chr.getAP() << " AP and is unarmed" << std::endl;
	return o;
}
