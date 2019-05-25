#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5, 21) { }
PlasmaRifle::~PlasmaRifle(void) { }
PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) { *this = src; }

PlasmaRifle &		PlasmaRifle::operator=(PlasmaRifle const & src)
{
	AWeapon::operator=(src);
	return *this;
}

void				PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
