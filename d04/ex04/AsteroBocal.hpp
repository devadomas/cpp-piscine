#ifndef ASTEROBOCAL_HPP
#define ASTEROBOCAL_HPP

#include "IAsteroid.hpp"

class AsteroBocal: public IAsteroid
{
public:
	AsteroBocal(void);
	virtual ~AsteroBocal(void);
	AsteroBocal(AsteroBocal const &);
	AsteroBocal &	operator=(AsteroBocal const &);

	std::string		beMined(StripMiner *) const;
	std::string		beMined(DeepCoreMiner *) const;
	std::string		getName(void) const;

private:

};

#endif
