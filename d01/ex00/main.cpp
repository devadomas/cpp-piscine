#include <iostream>
#include "Pony.hpp"

void		ponyOnTheHeap()
{
	Pony *miniaturePony = new Pony("Heaper");
	miniaturePony->setAge(10);
	delete miniaturePony;
}

void		ponyOnTheStack()
{
	Pony littleHorse("Stacker");
	littleHorse.setAge(-1);
}

int			main()
{
	std::cout << "Calling ponyOnTheHeap()" << std::endl;
	ponyOnTheHeap();
	std::cout << "Calling ponyOnTheStack()" << std::endl;
	ponyOnTheStack();
}
