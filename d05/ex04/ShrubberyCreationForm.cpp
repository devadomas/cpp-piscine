#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) { } // in private should never be called
ShrubberyCreationForm::~ShrubberyCreationForm(void) { }
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)  { *this = src; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm &			ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if (this != &src)
	{
		Form::operator=(src);
		this->_target = src._target;
	}
	return *this;
}


// sets&gets
std::string				ShrubberyCreationForm::getTarget(void) const { return this->_target; }
void					ShrubberyCreationForm::setTarget(std::string const & target) { this->_target = target; }

//
void					ShrubberyCreationForm::action(void) const
{
	std::ofstream		out;
	std::string			filename(this->_target + "_shrubbery");

	out.open(filename, std::ofstream::out);

	if (!out.is_open())
	{
		std::cerr << filename << ": " << std::strerror(errno) << std::endl;
		return ;
	}

	out << "       t                  t" << std::endl;
	out << "      .#.                .#." << std::endl;
	out << "     .###.              .###." << std::endl;
	out << "    .#%##%.            .#%##%." << std::endl;
	out << "   .%##%###.          .%##%###." << std::endl;
	out << "  .##%###%##.        .##%###%##." << std::endl;
	out << " .#%###%##%##.      .#%###%##%##." << std::endl;
	out << "       #                  #" << std::endl;
	out << "       #                  #" << std::endl;
	out.close();
}
