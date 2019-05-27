#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int			main(void)
{
	Bureaucrat		test("Test bot", 5);

	std::cout << "--- Test for form initialisation ---" << std::endl;
	try
	{
		Form		form("Super Form", 151, 2);
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << "Error occured why initialising: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << "Error occured why initialising: " << e.what() << std::endl;
	}
	std::cout << "--- Test for signing a from ---" << std::endl;

	Form		form("Super from", 6, 6);
	test.signForm(form);
	std::cout << "---- Some log info ----" << std::endl;
	std::cout << form;
	//
	std::cout << "--- Trying to sign form with a lowee grade bureaucrat ---" << std::endl;
	Form		form1("Not that great form", 1, 1);
	test.signForm(form1);
	//
	std::cout << "--- Test before from would be signed ---" << std::endl;
	Form		form2("High level form", 1, 1);
	try
	{
		form2.beSigned(test);
		std::cout << test.getName() << " can sign form " << form2.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << "form cannot be signed because: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << "form cannot be signed because: " << e.what() << std::endl;
	}
}
