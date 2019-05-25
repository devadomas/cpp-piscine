#include <iostream>
#include "Sorcerer.hpp"
#include "Victum.hpp"
#include "Peon.hpp"

int		main(void)
{
	std::cout << "--- Given tests ---" << std::endl;
	Sorcerer		robert("Robert", "the Magnificent");
	Victum			jim("Jimmy");
	Peon			joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	Sorcerer		john(robert); // Test for copy constructor
	john.polymorph(jim);
	std::cout << "--- /Given tests ---" << std::endl;

	Sorcerer		roberCpy(robert);
	Victum			jimCpy(jim);

	jimCpy.getPolymorphed();

	std::cout << "-- End of program  --" << std::endl;
	return (0);
}
