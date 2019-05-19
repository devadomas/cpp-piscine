#ifndef HUMAN_A_CLASS_HPP
# define HUMAN_A_CLASS_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const name, Weapon &weapon);
	~HumanA(void);
	void			attack(void);
private:
	std::string 	_name;
	Weapon&			_weapon;
};

#endif
