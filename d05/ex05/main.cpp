#include <sstream>
#include <iostream>
#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int			main(void)
{
	CentralBureaucracy			bigHouse;

	std::cout << "--- Testing for office size ---" << std::endl;
	for (int i = 0; i < 25; i++)
	{
		std::ostringstream s;
		s << "Test Bureaucrat " << i;
		Bureaucrat *		beur = new Bureaucrat(s.str(), rand() % 25);

		try
		{
			bigHouse.feed(beur);
			std::cout << s.str() << " was successfully assigned to office!" << std::endl;
		}
		catch (CentralBureaucracy::OfficesFullException & e)
		{
			std::cout << "cough exception of: " << e.what() << std::endl;
		}
	}
	std::cout << "--- Testing of target addition ---" << std::endl;

	for (int i = 0; i < 30; i++)
	{
		std::ostringstream s;
		s << "Test target " << i;
		try
		{
			bigHouse.queueUp(s.str());
			std::cout << s.str() << " was successfully queuedUP!" << std::endl;
		}
		catch(CentralBureaucracy::QueueIsFullException & e)
		{
			std::cout << "cought exception of: " << e.what() << std::endl;
		}
	}
	std::cout << "--- Lastly let's try to do some bureaucracy ---" << std::endl;
	try
	{
		bigHouse.doBureaucracy();
	}
	catch(std::exception & e)
	{
		std::cout << "exception cought: " << e.what() << std::endl;
	}
}
