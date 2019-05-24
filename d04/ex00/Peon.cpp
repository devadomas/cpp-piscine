#include <iostream>
#include "Peon.hpp"

Peon::Peon(void) : Victum() { }

Peon::Peon(std::string name): Victum(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const & src)
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
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
