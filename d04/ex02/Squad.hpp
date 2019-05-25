#ifndef SQUAD_HPP
#define SQUAD_HPP

#define NBR_MARINES	30

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:
	Squad(void);
	virtual ~Squad(void);
	Squad(Squad const & src);
	Squad &		operator=(Squad const & src);

	int					getCount(void) const;
	ISpaceMarine *		getUnit(int n) const;

	int					push(ISpaceMarine * marine);

private:
	int					_size;
	ISpaceMarine *		_arr[NBR_MARINES];

};

#endif
