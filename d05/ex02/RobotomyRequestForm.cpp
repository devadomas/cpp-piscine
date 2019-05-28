#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) { } // in private should never be called
RobotomyRequestForm::~RobotomyRequestForm(void) { }
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)  { *this = src; }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm &			RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	if (this != &src)
	{
		Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}


// sets&gets
std::string				RobotomyRequestForm::getTarget(void) const { return this->_target; }
void					RobotomyRequestForm::setTarget(std::string const & target) { this->_target = target; }

//
void					RobotomyRequestForm::action(void) const
{
	std::srand(std::time(NULL));
	std::cout << "*** Drilling noise *** (I HAVE NO IDEA HOW IT SOUNDS IN VERBAL FORM)" << std::endl;

	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " has not been robotomized... try again..." << std::endl;
}
