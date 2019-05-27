#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int			main(void)
{
	std::cout << "-- So it's time to give some work for poor intern --" << std::endl;
	Intern			john;
	std::string		arr[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation",
		"some random garbage"
	};

	Form 			*form;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "-----" << std::endl;
		try
		{
			form = john.makeForm(arr[i], "Dope things to pass");
			std::cout << "Intern did a amazing job and created form" << std::endl;
		}
		catch (Intern::InternNoFormFoundException & e)
		{
			std::cout << "Intern was not able to create form because: " << e.what() << std::endl;
		}
		delete form;
		form = NULL;
	}
}
