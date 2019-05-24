#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include "Victum.hpp"

class Peon : public Victum
{
public:
	Peon(void);
	Peon(std::string name);
	Peon(Peon const & src);
	virtual ~Peon(void);
	Peon &		operator=(Peon const & rhs);
	void		getPolymorphed(void) const;

private:
	std::string		_name;
};

#endif
