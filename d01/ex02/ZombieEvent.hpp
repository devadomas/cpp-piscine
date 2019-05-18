#ifndef ZOMBIEEVENT_CLASS_HPP
# define ZOMBIEEVENT_CLASS_HPP

# include <iostream>
# include <string>

class ZombieEvent
{
public:
	bool setZombieType(std::string name);
	Zombie* newZombie(std::string name);
private:

};

#endif
