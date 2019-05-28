#include <iostream>
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int			main(void)
{
	std::cout << "--- Creatimg empty office ---" << std::endl;
	Intern						intern;
	Bureaucrat					signer("Signer", 1);
	Bureaucrat					executor("Executor", 1);
	OfficeBlock					office;
	PresidentialPardonForm		form("haha");

	try
	{
		office.doBureaucracy(form, "Some guy");
	}
	catch (OfficeBlock::OfficeNotFilledException & e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	std::cout << "--- Now we will try to set people to work! ---" << std::endl;
	office.setIntern(&intern);
	office.setSigner(&signer);
	office.setExecutor(&executor);
	try
	{
		office.doBureaucracy(form, "Some guy");
	}
	catch (OfficeBlock::OfficeNotFilledException & e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
}
