#ifndef VICTUM_CLASS_HPP
# define VICTUM_CLASS_HPP

# include <iostream>
# include <string>

class Victum
{
public:
	Victum(std::string name);
	virtual ~Victum(void);
	std::string		getName(void) const;
	virtual void	getPolymorphed(void) const;

private:
	std::string		_name;
};

std::ostream & operator<<(std::ostream & o, Victum const & vic);

#endif
