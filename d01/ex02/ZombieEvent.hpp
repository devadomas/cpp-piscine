#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	bool			setZombieType(std::string const type);
	Zombie*			newZombie(std::string const name);

private:
	std::string		_type;
};

#endif
