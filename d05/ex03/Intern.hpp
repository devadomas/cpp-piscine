#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
public:
	Form *		makeForm(std::string const &, std::string const) const;
	Form *		makeRobotomyRequestForm(std::string const) const;
	Form *		makePresidentialPardonForm(std::string const) const;
	Form *		makeShrubberyCreationForm(std::string const) const;

	// exceptions
	class InternNoFormFoundException : public std::exception
	{
		public:
			InternNoFormFoundException(void);
			InternNoFormFoundException(InternNoFormFoundException const &);
			virtual ~InternNoFormFoundException(void) throw();
			InternNoFormFoundException &		operator=(InternNoFormFoundException const &);
			virtual const char *		what(void) const throw();
	};
};

#endif
