#include <iostream>
#include "Peon.hpp"

Peon::Peon(void) : Victum() {} // Plane constr.

Peon::Peon(std::string name): Victum(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) // Destructor
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const & src) // Copy constructor
{
	*this = src;
}

Peon &			Peon::operator=(Peon const & src)
{
	if (this != &src)
		this->_name = src.getName();
	return *this;
}

void			Peon::getPolymorphed(void) const
{
	// std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
