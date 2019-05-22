#include <string>
#include <iostream>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

static void		randomChump(void)
{
	std::string const names[] = {
		"Sefton Patton",
		"Becka Ferdinand",
		"Ozzie Russel",
		"Spring Woodie",
		"Laura Blondie",
		"Hellen Sylvester",
		"Ludwig Kendra",
		"Brooks Cymone",
		"Raphaela Aurel",
		"Frank Elaina"
	};

	Zombie zombie = Zombie("Stacker", names[std::rand() % 10]);
	zombie.announce();
}

static void		zombieOnHeap(void)
{
	Zombie		*zombie;
	ZombieEvent	zEvent = ZombieEvent();

	zEvent.setZombieType("Heaper");
	zombie = zEvent.newZombie("Paul Escobar");
	zombie->announce();
	delete zombie;
}

int				main(void)
{
	// for rand() to work
	std::srand(std::time(nullptr));
	// zombie on stack
	randomChump();
	// zombie on heap
	zombieOnHeap();
}
