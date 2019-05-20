#ifndef SORCERER_CLASS_HPP
# define SORCERER_CLASS_HPP

# include <iostream>
# include "Victum.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer(void);
	std::string		getName(void) const;
	std::string		getTitle(void) const;
	void			polymorph(Victum const &) const;

private:
	std::string		_name;
	std::string		_title;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & sor);

#endif
