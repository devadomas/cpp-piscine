#include "Intern.hpp"

Form *			Intern::makeRobotomyRequestForm(std::string const target) const
{
	return new RobotomyRequestForm(target);
}

Form *			Intern::makePresidentialPardonForm(std::string const target) const
{
	return new PresidentialPardonForm(target);
}

Form *			Intern::makeShrubberyCreationForm(std::string const target) const
{
	return new ShrubberyCreationForm(target);
}

Form *			Intern::makeForm(std::string const & request, std::string const target) const
{
	std::string		arr[] = {
		"robotomy request",
		"presidential pardon"
		"shrubbery creation"
	};
	typedef Form* (Intern::*FormCreation)(std::string const) const;
	FormCreation		forms[] = {
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm
	};


	for (int i = 0; i < 3; i++)
		if (request == arr[i])
		{
			std::cout << "Intern is about to create " << request << " form" << std::endl;
			return (this->*(forms[i]))(target);
		}
	throw Intern::InternNoFormFound();
	return NULL;
}

Intern::InternNoFormFoundException::InternNoFormFoundException(void) { }
Intern::InternNoFormFoundException::~InternNoFormFoundException(void) throw() { }
Intern::InternNoForInternNoFormFoundExceptionmFound::InternNoFormFoundException(InternNoFormFoundException const &src) { *this = src; }
Intern::InternNoFormFoundException & Intern::InternNoFormFoundException::operator=(Intern::InternNoFormFoundException const &) { return *this; }
const char * Intern::InternNoFormFoundException::what(void) const throw() { return ("no matching form found"); }
