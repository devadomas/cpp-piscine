#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void): AWeapon("Power Fist", 8, 50) { }
PowerFist::~PowerFist(void) { }
PowerFist::PowerFist(PowerFist const & src) { *this = src; }

PowerFist &			PowerFist::operator=(PowerFist const & src)
{
	AWeapon::operator=(src);
	return *this;
}

void				PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
