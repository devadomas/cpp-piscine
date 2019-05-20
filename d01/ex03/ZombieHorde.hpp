#ifndef ZOMBIE_HORDE_CLASS_HPP
# define ZOMBIE_HORDE_CLASS_HPP

# include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void		announce(void);

private:
	Zombie*	_zombies;
	int		_n;
};

#endif