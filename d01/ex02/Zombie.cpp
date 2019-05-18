#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type): _type(type), _name(name)
{
	// nothing needed I guess
}

Zombie::~Zombie()
{
	// baaah DEAD
}

void	Zombie::announce() const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}
