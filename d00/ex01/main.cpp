#include <iostream>
#include "Phonebook.class.hpp"

int		main(void)
{
	welcomeMsg();
	phonebookLoop();
	std::cout << "Sorry to see you go! Your data has been wiped..." << std::endl;
	std::cout << "See you next time!" << std::endl;
}
