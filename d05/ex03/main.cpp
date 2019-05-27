#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int			main(void)
{
	Bureaucrat		test("Test bot", 1); // Bureaucrat with highest level possible
	std::cout << "We have a superior Bureaucrat: " << std::endl;
	std::cout << test;

	std::cout << "--- We have something to sign ---" << std::endl;

	PresidentialPardonForm		president("Miss Pressidency");
	std::cout << president;

	try
	{
		president.execute(test);
	}
	catch(Form::FormIsNotSignedException & e)
	{
		std::cout << "Error occured while trying to execute: " << e.what() << std::endl;
	}
	std::cout << "--- Well if from is not singed. We have sign it! ---" << std::endl;
	test.signForm(president);
	std::cout << "--- We signed it so it's time to execute!!! ---" << std::endl;
	try
	{
		president.execute(test);
	}
	catch(Form::FormIsNotSignedException & e)
	{
		std::cout << "Error occured while trying to execute: " << e.what() << std::endl;
	}
	std::cout << "--- A little bit of action() for the end ---" << std::endl;
	president.action();

	std::cout << "-- another form for testing of executeForm() from Bureaucrat" << std::endl;
	ShrubberyCreationForm				hardTitleForm("Some simple form");
	test.executeForm(hardTitleForm);
	test.signForm(hardTitleForm);
	std::cout << "-- well finally I can try executeForm command --" << std::endl;
	test.executeForm(hardTitleForm);
}
