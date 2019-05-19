#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const name);
	~HumanB(void);
	void			setWeapon(Weapon& weapon);
	void			attack(void);
private:
	std::string 	_name;
	Weapon*			_weapon;
};

#endif
