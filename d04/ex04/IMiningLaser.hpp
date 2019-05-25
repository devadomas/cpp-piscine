#ifndef IMININGLASER
#define IMININGLASER

#include "IAsteroid.hpp"

class IMiningLaser
{
public:
	virtual		~IMiningLaser(void)	{}
	virtual	void	mine(IAsteroid *) = 0;
};

#endif
