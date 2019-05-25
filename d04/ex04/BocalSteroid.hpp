#ifndef BOCALSTEROID_HPP
#define BOCALSTEROID_HPP

#include "IAsteroid.hpp"

class BocalSteroid: public IAsteroid
{
public:
	BocalSteroid(void);
	virtual ~BocalSteroid(void);
	BocalSteroid(BocalSteroid const &);
	BocalSteroid &	operator=(BocalSteroid const &);

	std::string		beMined(StripMiner *) const;
	std::string		beMined(DeepCoreMiner *) const;
	std::string		getName(void) const;

private:

};

#endif
