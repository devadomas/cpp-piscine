#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & src);
	virtual ~PlasmaRifle(void);
	PlasmaRifle &		operator=(PlasmaRifle const & src);
	
	void				attack(void) const;
};

#endif
