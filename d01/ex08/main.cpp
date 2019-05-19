#include "Human.hpp"

int		main(void)
{
	Human		humanoid;

	humanoid.action("rangedAttack", "someone");
	humanoid.action("intimidatingShout", "someone");
	humanoid.action("meleeAttack", "someone");
	humanoid.action("asdas", "someone"); // some garbage to test
}
