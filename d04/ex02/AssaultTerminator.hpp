#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "TacticalMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const & src);
	virtual					~AssaultTerminator(void);
	AssaultTerminator &		operator=(AssaultTerminator const &);

	void					battleCry(void) const;
	void 					rangedAttack(void) const;
	void					meleeAttack(void) const;
	ISpaceMarine *			clone(void) const;
};

#endif
