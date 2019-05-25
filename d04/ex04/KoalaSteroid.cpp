#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid(void) { }
BocalSteroid::~BocalSteroid(void) { }
BocalSteroid::BocalSteroid(BocalSteroid const & src) { *this = src;}

BocalSteroid &		BocalSteroid::operator=(BocalSteroid const &) { return *this; }

std::string			BocalSteroid::getName(void) const { return "BocalSteroid"; }

std::string			BocalSteroid::beMined(StripMiner *) const { return "Krpite"; }
std::string			BocalSteroid::beMined(DeepCoreMiner *) const { return "Zazium";}
