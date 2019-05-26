#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) { } // private constructor
Bureaucrat::~Bureaucrat(void) { }
Bureaucrat::Bureaucrat(Bureaucrat const & src) { *this = src; }

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat &			Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_grade = src.getGrade();
	}
	return *this;
}

//

std::string 		Bureaucrat::getName(void) const { return this->_name; }
int					Bureaucrat::getGrade(void) const { return this->_grade; }

void				Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void				Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << "Bureaucrat class: name: " << src.getName() << "|grade: " << src.getGrade() << std::endl;
	return o;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() { }
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) { *this = src; }
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &) { return *this; }
const char * Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Grade is too low"); }

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { }
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { }
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) { *this = src; }
Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &) { return *this; }
const char * Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Grade is too high"); }
