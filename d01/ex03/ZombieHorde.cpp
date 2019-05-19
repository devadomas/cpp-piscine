#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
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
	if (n < 0)
		throw "can't be negative number";
	this->_n = n;
	this->_zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		this->_zombies[i].setName(names[rand() % 10]);
		this->_zombies[i].setType("Drunkhead");
		this->_zombies[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->_zombies;
}
