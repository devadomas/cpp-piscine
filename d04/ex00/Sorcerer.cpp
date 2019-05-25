#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) { } // should never be called

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
}

Sorcerer &		Sorcerer::operator=(Sorcerer const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_title = src.getTitle();
	}
	return *this;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string		Sorcerer::getName(void) const { return this->_name; }
void 			Sorcerer::setName(std::string const & name) { this->_name = name; }
std::string		Sorcerer::getTitle(void) const { return this->_title; }
void			Sorcerer::setTitle(std::string const & title) { this->_title = title; }

std::ostream & operator<<(std::ostream & o, Sorcerer const & sor)
{
	o << "I am " << sor.getName() << ", " << sor.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

void			Sorcerer::polymorph(Victum const & vic) const
{
	vic.getPolymorphed();
}
