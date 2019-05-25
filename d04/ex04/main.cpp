#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"

int		main(void)
{
	IAsteroid* kreog = new AsteroBocal();
	IAsteroid* koala = new BocalSteroid();

	IMiningLaser* deepCore = new DeepCoreMiner();
	IMiningLaser* strip = new StripMiner();
	IMiningLaser* stripBis = new StripMiner();
	IMiningLaser* stripTer = new StripMiner();

	MiningBarge* miningBarge = new MiningBarge();

	std::cout << "DeepCoreMiner mining AsteroKreog" << std::endl;
	deepCore->mine(kreog);

	std::cout << std::endl << "DeepCoreMiner mining KoalaSteroid" << std::endl;
	deepCore->mine(koala);

	std::cout << std::endl << "StripMiner mining AsteroKreog" << std::endl;
	strip->mine(kreog);

	std::cout << std::endl << "StripMiner mining KoalaSteroid" << std::endl;
	strip->mine(koala);

	std::cout << std::endl << "Lets equip MiningBarge with 2 weapons" << std::endl;
	miningBarge->equip(deepCore);
	miningBarge->equip(strip);

	std::cout << std::endl << "MINE MICROSOFT DEVELOPERS !" << std::endl;
	miningBarge->mine(kreog);

	std::cout << std::endl << "Lets copy the mining barge to dig more and more AsteroKreog" << std::endl;
	MiningBarge anotherMiningBarge(*miningBarge);
	anotherMiningBarge.mine(kreog);

	std::cout << std::endl << "Lets assign a new mining barge, equip it and dig this shit" << std::endl;
	MiningBarge assignMiningBarge = anotherMiningBarge;
	assignMiningBarge.equip(stripBis);
	assignMiningBarge.equip(stripTer);
	assignMiningBarge.mine(kreog);

	delete kreog;
	delete koala;
	delete deepCore;
	delete strip;
	delete stripBis;
	delete stripTer;
	delete miningBarge;
	return 0;
}
