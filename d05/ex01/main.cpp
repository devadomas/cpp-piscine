#include <iostream>
#include "Bureaucrat.hpp"

int			main(void)
{
	for (int i = 0; i < 160; i += 5)
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Trying to create a Test bot with grade: " << i << std::endl;
		try
		{
			Bureaucrat		test("Test bot", i);
			std::cout << test;
		}
		catch (Bureaucrat::GradeTooLowException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
	}
	std::cout << "--- Different tests TESTS ---" << std::endl;
	Bureaucrat		test("Test bot", 150);
	for (int i = 0; i < 160; i++)
	{
		try
		{
			test.incrementGrade();
			std::cout << test;
		}
		catch (Bureaucrat::GradeTooLowException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
	}
	std::cout << "NOW other way!!" << std::endl;
	for (int i = 0; i < 160; i++)
	{
		try
		{
			test.decrementGrade();
			std::cout << test;
		}
		catch (Bureaucrat::GradeTooLowException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException & e) {
			std::cout << "exception cought on: " << e.what() << std::endl;
		}
	}
}
