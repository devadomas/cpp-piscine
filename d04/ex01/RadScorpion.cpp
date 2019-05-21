#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src)
{
	*this = src;
}

RadScorpion &		RadScorpion::operator=(RadScorpion const & src)
{
	if (this != &src)
		Enemy::operator=(src);
	return *this;
}

void				RadScorpion::takeDamage(int damage)
{
	int hp;

	hp = this->getHp();
	this->setHp(hp - damage);
}
