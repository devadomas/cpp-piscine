#include "Form.hpp"

Form::Form(void) { }
Form::~Form(void) { }

Form::Form(std::string const name, int gradeSign, int gradeExecute):
	_name(name),
	_signed(false)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooLowException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooHighException();
	this->_gradeSign = gradeSign;
	this->_gradeExecute = gradeExecute;
}

Form::Form(Form const &src) { *this = src; }
Form &			Form::operator=(Form const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_signed = src._signed;
		this->_gradeSign = src._gradeSign;
		this->_gradeExecute = src._gradeExecute;
	}
	return *this;
}

std::string		Form::getName(void) const { return this->_name; }
bool			Form::isSigned(void) const { return this->_signed; }

void			Form::beSigned(Bureaucrat const & obj)
{
	if (obj.getGrade() > this->_gradeSign) // if Bureaucrat grade is too low
		throw Form::GradeTooLowException();
	this->_signed = true;

}

std::ostream &			operator<<(std::ostream & o, Form const & form)
{
	o << "Form status: " << std::endl
		<< "Name: " << form.getName() << std::endl
		<< "Signed status: " << form.isSigned() << std::endl;
	return o;
}


Form::GradeTooLowException::GradeTooLowException(void) { }
Form::GradeTooLowException::~GradeTooLowException(void) throw() { }
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) { *this = src; }
Form::GradeTooLowException & Form::GradeTooLowException::operator=(Form::GradeTooLowException const &) { return *this; }
const char * Form::GradeTooLowException::what(void) const throw() { return ("Grade is too low"); }

Form::GradeTooHighException::GradeTooHighException(void) { }
Form::GradeTooHighException::~GradeTooHighException(void) throw() { }
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) { *this = src; }
Form::GradeTooHighException & Form::GradeTooHighException::operator=(Form::GradeTooHighException const &) { return *this; }
const char * Form::GradeTooHighException::what(void) const throw() { return ("Grade is too high"); }
