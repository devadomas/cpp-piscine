#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const name, Weapon &weapon);
	~HumanA(void);
	void			attack(void) const;
	

private:
	std::string 	_name;
	Weapon&			_weapon;
};

#endif
