#include <iostream>
#include "Victum.hpp"

Victum::Victum(std::string name): _name(name)
{
	std::cout << "Some random victum called " << name << " just popped !" << std::endl;
}

Victum::~Victum(void)
{
	std::cout << "Victum " << this->_name << " just died for no apparent reason !" << std::endl;
}

std::string		Victum::getName(void) const
{
	return this->_name;
}

std::ostream & operator<<(std::ostream & o, Victum const & vic)
{
	o << "I'm " << vic.getName() << " and I like otters !" << std::endl;
	return o;
}

void			Victum::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute litle sheep !" << std::endl;
}
