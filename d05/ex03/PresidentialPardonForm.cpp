#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) { } // in private should never be called
PresidentialPardonForm::~PresidentialPardonForm(void) { }
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)  { *this = src; }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("PresidentialPardonForm", 25, 5), _target(target) { }

PresidentialPardonForm &			PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	if (this != &src)
	{
		Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}


// sets&gets
std::string				PresidentialPardonForm::getTarget(void) const { return this->_target; }
void					PresidentialPardonForm::setTarget(std::string const & target) { this->_target = target; }

//
void					PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
