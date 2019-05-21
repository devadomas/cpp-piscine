#ifndef SORCERER_CLASS_HPP
# define SORCERER_CLASS_HPP

# include <iostream>
# include "Victum.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	~Sorcerer(void);
	Sorcerer &		operator=(Sorcerer const & src);
	std::string		getName(void) const;
	bool			setName(std::string const & name);
	std::string		getTitle(void) const;
	bool			setTitle(std::string const & title);
	void			polymorph(Victum const &) const;

private:
	Sorcerer(void);
	std::string		_name;
	std::string		_title;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & sor);

#endif
