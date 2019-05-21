#ifndef A_WEAPON_CLASS_HPP
# define A_WEAPON_CLASS_HPP

# include <string>

class AWeapon
{
public:
	AWeapon(void);
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	virtual ~AWeapon(void);
	AWeapon	&			operator=(AWeapon const & src);
	std::string			getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;
	bool				setName(std::string const & name);
	void				setAPCost(int cost);
	void				setDamage(int damage);
	virtual void		attack(void) const = 0;

private:
	std::string			_name;
	int					_valueAP;
	int					_damage;
};

#endif
