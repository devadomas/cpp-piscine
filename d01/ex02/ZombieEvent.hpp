#ifndef ZOMBIEEVENT_CLASS_HPP
# define ZOMBIEEVENT_CLASS_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	bool setZombieType(std::string const type);
	Zombie* newZombie(std::string const name);
private:
	std::string		_type;
};

#endif
