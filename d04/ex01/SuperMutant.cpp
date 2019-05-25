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

SuperMutant::SuperMutant(SuperMutant const & src) { *this = src; }

SuperMutant &		SuperMutant::operator=(SuperMutant const & src)
{
	Enemy::operator=(src);
	return *this;
}

void				SuperMutant::takeDamage(int damage) { Enemy::takeDamage(damage - 3); }
