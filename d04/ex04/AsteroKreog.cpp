#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal(void) { }
AsteroBocal::~AsteroBocal(void) { }
AsteroBocal::AsteroBocal(AsteroBocal const & src) { *this = src;}

AsteroBocal &		AsteroBocal::operator=(AsteroBocal const &) { return *this; }

std::string			AsteroBocal::getName(void) const { return "AsteroBocal"; }

std::string			AsteroBocal::beMined(StripMiner *) const { return "Flavium"; }
std::string			AsteroBocal::beMined(DeepCoreMiner *) const { return "Thorite";}
