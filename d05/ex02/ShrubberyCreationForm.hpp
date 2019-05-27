#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm &		operator=(ShrubberyCreationForm const &);


	// sets&gets
	std::string			getTarget(void) const;
	void				setTarget(std::string const &);

	void				action(void) const; // for custom action.

private:
	ShrubberyCreationForm(void);
	std::string			_target;
};

#endif
