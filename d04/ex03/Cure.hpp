#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	virtual ~Cure(void);
	Cure(Cure const & src);
	Cure &		operator=(Cure const & src);

	void		use(ICharacter& target);
	AMateria *	clone(void) const;

};

#endif
