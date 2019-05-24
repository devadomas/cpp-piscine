#ifndef VICTUM_HPP
# define VICTUM_HPP

# include <iostream>
# include <string>

class Victum
{
public:
	Victum(void);
	Victum(std::string name);
	Victum(Victum const & src);
	virtual ~Victum(void);
	Victum &		operator=(Victum const & src);
	std::string		getName(void) const;
	bool			setName(std::string const & name);
	virtual void	getPolymorphed(void) const;

private:
	std::string		_name;
};

std::ostream & operator<<(std::ostream & o, Victum const & vic);

#endif
