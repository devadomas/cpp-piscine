#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form; // import of form

class Bureaucrat
{
public:
	Bureaucrat(std::string const src, int grade);
	virtual ~Bureaucrat(void);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &			operator=(Bureaucrat const &);

	//
	std::string				getName(void) const;
	int						getGrade(void) const;

	void					incrementGrade(void);
	void					decrementGrade(void);

	void 					signForm(Form &) const;
	void					executeForm(Form const &);

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

private:
	Bureaucrat(void);

	std::string				_name;
	int						_grade;

};

std::ostream &				operator<<(std::ostream &, Bureaucrat const &);

#endif
