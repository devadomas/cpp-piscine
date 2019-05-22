#include <string>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void): _type("") { }
ZombieEvent::~ZombieEvent(void) { }

bool			ZombieEvent::setZombieType(std::string const type)
{
	if (type.length() == 0)
		return false;
	this->_type = type;
	return true;
}

Zombie*			ZombieEvent::newZombie(std::string const name)
{
	return new Zombie(name, this->_type);
}
