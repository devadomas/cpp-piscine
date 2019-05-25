#ifndef STRIPMINER_HPP
#define STRIPMINER_HPP

#include <iostream>
#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
	StripMiner(void);
	virtual ~StripMiner(void);
	StripMiner(StripMiner const &);
	StripMiner &		 operator=(StripMiner const &);

	void				mine(IAsteroid *);
};

#endif
