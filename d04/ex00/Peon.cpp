#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string name): Victum(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

void			Peon::getPolymorphed(void) const
{
	// std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
