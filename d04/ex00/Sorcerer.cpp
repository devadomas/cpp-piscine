#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string		Sorcerer::getName(void) const
{
	return this->_name;
}

std::string		Sorcerer::getTitle(void) const
{
	return this->_title;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & sor)
{
	o << "I am " << sor.getName() << ", " << sor.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

void			Sorcerer::polymorph(Victum const & vic) const
{
	vic.getPolymorphed();
}
