#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
public:
	TacticalMarine(void);
	virtual ~TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);
	TacticalMarine &	operator=(TacticalMarine const &);

	ISpaceMarine*		clone(void) const;

	void				battleCry(void) const;
	void				rangedAttack(void) const;
	void				meleeAttack(void) const;
};

#endif
