#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP

#include <iostream>
#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner(void);
	virtual ~DeepCoreMiner(void);
	DeepCoreMiner(DeepCoreMiner const &);
	DeepCoreMiner &		 operator=(DeepCoreMiner const &);

	void				mine(IAsteroid *);
};

#endif
