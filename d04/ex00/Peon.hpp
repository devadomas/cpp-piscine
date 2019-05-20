#ifndef PEON_CLASS_HPP
# define PEON_CLASS_HPP

# include <string>
# include "Victum.hpp"

class Peon : public Victum
{
public:
	Peon(std::string name);
	virtual ~Peon(void);
	void		getPolymorphed(void) const;

private:
	std::string		_name;
};

#endif
