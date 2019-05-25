#include <iostream>
#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int			main(void)
{
	/*
		TODO: Write A MAIN AND TESTS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		Create logger or something!
	*/

	Character* zaz = new Character("zaz");
	std::cout << *zaz;

	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	delete zaz;
	delete b;
	delete pr;
	delete pf;

	std::cout << "-- more tests --" << std::endl;

	Character		charr("Some");
	PlasmaRifle		some;
	RadScorpion		scorp;

	charr.equip(&some);
	std::cout << charr;
	charr.attack(&scorp);
	std::cout << charr;

	std::cout << "--- Assignation test ---" << std::endl;
	Character		asign = charr;

	std::cout << asign;

	std::cout << "--- Copy test ---" << std::endl;

	Character		copy(asign);
	std::cout << copy;

	std::cout << "--- END OF PROGRAM ---" << std::endl;
	return 0;
}
