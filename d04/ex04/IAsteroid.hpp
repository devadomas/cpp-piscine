#ifndef IASTEROID_HPP
#define IASTEROID_HPP

#include <iostream>

class DeepCoreMiner;
class StripMiner;

class IAsteroid
{
public:
	virtual ~IAsteroid(void) { }
	virtual std::string		beMined(StripMiner *) const = 0;
	virtual std::string		beMined(DeepCoreMiner *) const = 0;
	virtual std::string		getName(void) const = 0;
};

#endif
