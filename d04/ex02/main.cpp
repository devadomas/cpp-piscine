#include <iostream>
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

int		main(void)
{
	ISpaceMarine *		bob = new TacticalMarine;
	ISpaceMarine *		jim = new AssaultTerminator;

	ISquad *			vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *	cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "--- my tests ---" << std::endl;
	std::cout << "Current Squad size: " << vlc->getCount() << std::endl;

	ISpaceMarine* memberIndex2 = new TacticalMarine;
	ISpaceMarine* memberIndex3 = memberIndex2->clone();
	ISpaceMarine* memberIndex4 = memberIndex2->clone();
	ISpaceMarine* memberIndex5 = memberIndex2->clone();
	ISpaceMarine* memberIndex6 = new AssaultTerminator;
	ISpaceMarine* memberIndex7 = memberIndex6->clone();
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex2) << std::endl;
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex3) << std::endl;
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex4) << std::endl;
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex5) << std::endl;
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex6) << std::endl;
	std::cout << "Squad size after pushing new member : " << vlc->push(memberIndex7) << std::endl;

	delete vlc;
	return 0;
}
