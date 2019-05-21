#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) {}

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

std::string		Sorcerer::getName(void) const
{
	return this->_name;
}

bool			Sorcerer::setName(std::string const & name)
{
	if (name.length() == 0)
		return false;
	this->_name = name;
	return true;
}

std::string		Sorcerer::getTitle(void) const
{
	return this->_title;
}

bool			Sorcerer::setTitle(std::string const & title)
{
	if (title.length() == 0)
		return false;
	this->_title = title;
	return true;
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
