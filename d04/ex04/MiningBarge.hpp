#ifndef MININGBRAGE_HPP
#define MININGBRAGE_HPP

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
public:
	MiningBarge(void);
	virtual ~MiningBarge(void);
	MiningBarge(MiningBarge const &);
	MiningBarge &		operator=(MiningBarge const &);

	void		equip(IMiningLaser *);
	void		mine(IAsteroid *) const;

private:
	IMiningLaser *		_arr[4];

};

#endif
