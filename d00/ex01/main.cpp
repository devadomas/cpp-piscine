#include "Phonebook.class.hpp"
#include <iostream>

int		main(void)
{
	welcomeMsg();
	phonebookLoop();
	std::cout << "Sorry to see you go! Your data has been wiped..." << std::endl;
	std::cout << "See you next time!" << std::endl;
}
