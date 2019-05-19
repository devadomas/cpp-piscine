#include "Human.hpp"
#include <iostream>

void		Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack was made on " << target << std::endl;
}

void		Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack was made on " << target << std::endl;
}

void		Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout was made on " << target << std::endl;
}

void		Human::action(std::string const & action_name, std::string const & target)
{
	void (Human::*list[])(std::string const &) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	std::string cmd[] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	for (int i = 0; i < 3; i++)
	{
		if (cmd[i] == action_name)
		{
			(this->*list[i])(target);
			break ;
		}
	}
}
