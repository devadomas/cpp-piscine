#include <iostream>
#include "Sorcerer.hpp"
#include "Victum.hpp"
#include "Peon.hpp"

int		main(void)
{
	Sorcerer		robert("Robert", "the Magnificent");

	Victum			jim("Jimmy");
	Peon			joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);
	return (0);
}
