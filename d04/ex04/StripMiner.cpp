#include "StripMiner.hpp"

StripMiner::StripMiner(void) { }
StripMiner::~StripMiner(void) { }
StripMiner::StripMiner(StripMiner const & src) { *this = src; }
StripMiner &		StripMiner::operator=(StripMiner const &) { return *this; }

void 				StripMiner::mine(IAsteroid * target)
{
	std::cout << "* strip mining ... got " << target->beMined(this) << " ! *" << std::endl;
}
