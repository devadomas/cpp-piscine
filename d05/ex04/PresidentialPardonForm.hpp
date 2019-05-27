#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm &		operator=(PresidentialPardonForm const &);


	// sets&gets
	std::string			getTarget(void) const;
	void				setTarget(std::string const &);

	void				action(void) const; // for custom action.

private:
	PresidentialPardonForm(void);
	std::string			_target;
};

#endif
