#include <iostream>
#include "Cure.hpp"

Cure::Cure(void): _type("cure") { }

Cure::~Cure(void) { }

Cure::Cure(Cure const & src)
{
	*this = src;
}

Cure &		Ice::operator=(Cure const & src)
{
	if (this != &src)
	{
		this->xp = src.getXP();
		thos->_type = src.getType();
	}
	return *this;
}

//

void		Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}

AMateria *	Cure::clone(void) const
{
	return new Cure(*this);
}
