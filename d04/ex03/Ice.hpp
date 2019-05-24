#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	virtual ~Ice(void);
	Ice(Ice const & src);
	Ice &		operator=(Ice const & src);

	void		use(ICharacter& target);
	AMateria *	clone(void) const;

};

#endif
