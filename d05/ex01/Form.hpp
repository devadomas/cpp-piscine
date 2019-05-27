#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
public:
	Form(std::string const, int, int);
	virtual		~Form(void);
	Form(Form const &);
	Form &		operator=(Form const &);
	//
	void		beSigned(Bureaucrat const &);
	//
	std::string	getName(void) const;
	bool		isSigned(void) const;
	// exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void);
			GradeTooHighException(GradeTooHighException const &);
			virtual ~GradeTooHighException(void) throw();
			GradeTooHighException &		operator=(GradeTooHighException const &);
			virtual const char *		what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void);
			GradeTooLowException(GradeTooLowException const &);
			virtual ~GradeTooLowException(void) throw();
			GradeTooLowException &		operator=(GradeTooLowException const &);
			virtual const char *		what(void) const throw();
	};
	//
private:
	Form(void);

	std::string			_name;
	bool						_signed;
	int					_gradeSign;
	int					_gradeExecute;

};

std::ostream &			operator<<(std::ostream &, Form const &);

#endif
