#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character(std::string const & name);
	Character(Character const & src);
	~Character();
	Character &			operator=(Character const & src);

	void				recoverAP(void);
	void				equip(AWeapon *wpn);
	void				attack(Enemy *enemy);
	std::string			getName(void) const;
	AWeapon *			getWeapon(void) const;
	int					getAP(void) const;

private:
	std::string			_name;
	int					_valueAP;
	AWeapon	*			_wpn;
};

std::ostream & operator<<(std::ostream & o, Character const & chr);

#endif
