#ifndef VICTUM_HPP
# define VICTUM_HPP

# include <iostream>
# include <string>

class Victum
{
public:
	Victum(std::string name);
	Victum(Victum const & src);
	virtual ~Victum(void);
	Victum &		operator=(Victum const & src);

	std::string		getName(void) const;
	void			setName(std::string const & name);
	virtual void	getPolymorphed(void) const;

private:
	Victum(void);
	std::string		_name;
};

std::ostream & operator<<(std::ostream & o, Victum const & vic);

#endif
