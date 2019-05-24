#include <iostream>
#include "Ice.hpp"

Ice::Ice(void): _type("ice") { }

Ice::~Ice(void) { }

Ice::Ice(Ice const & src)
{
	*this = src;
}

Ice &		Ice::operator=(Ice const & src)
{
	if (this != &src)
	{
		this->xp = src.getXP();
		thos->_type = src.getType();
	}
	return *this;
}

//

void		Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ce bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

AMateria *	Ice::clone(void) const
{
	return new Ice(*this);
}
