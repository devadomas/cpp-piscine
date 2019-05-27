#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm &		operator=(RobotomyRequestForm const &);


	// sets&gets
	std::string			getTarget(void) const;
	void				setTarget(std::string const &);

	void				action(void) const; // for custom action.

private:
	RobotomyRequestForm(void);
	std::string			_target;
};

#endif
