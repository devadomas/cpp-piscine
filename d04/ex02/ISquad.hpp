#ifndef		ISQUAD_HPP
#define		ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual					~ISquad(void) { }
	virtual int				getCount(void) const = 0;
	virtual	ISpaceMarine *	getUnit(int) const = 0;
	virtual int				push(ISpaceMarine *) = 0;
};

#endif
