#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "SuperMutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src)
{
	*this = src;
}

SuperMutant &		SuperMutant::operator=(SuperMutant const & src)
{
	if (this != &src)
		Enemy::operator=(src);
	return *this;
}

void				SuperMutant::takeDamage(int damage)
{
	// TODO: improve damage system
	damage -= 3;
	if (damage < 0)
		damage = 0;
	this->setHp(this->getHp() - damage);
}
