#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const & src);
	virtual ~PowerFist(void);
	PowerFist &			operator=(PowerFist const & src);

	void				attack(void) const;
};

#endif
