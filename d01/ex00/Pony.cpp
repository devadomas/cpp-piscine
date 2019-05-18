#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name): _name(name)
{
	std::cout << "Pony with a name " << this->_name << " initialised" << std::endl;
	this->_age = 0;
}

Pony::~Pony()
{
	std::cout << "Pony with a name " << this->_name << " died..." << std::endl;
	std::cout << "Kidna sad..." << std::endl;
}

bool Pony::setAge(int age)
{
	if (age < 0)
	{
		std::cout << "It's impossible to set negatve age for Pony(" << this->_name << ")" << std::endl;
		return (false);
	}
	this->_age = age;
	std::cout << "Setting age for Pony(" << this->_age << ")" << std::endl;
	return (true);
}

int Pony::getAge() const
{
	return (this->_age);
}
