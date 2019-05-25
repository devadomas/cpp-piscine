#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

# include <string>

class AWeapon
{
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	virtual ~AWeapon(void);
	AWeapon	&			operator=(AWeapon const & src);


	std::string			getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;
	void				setName(std::string const & name);
	void				setAPCost(int cost);
	void				setDamage(int damage);

	virtual void		attack(void) const = 0;

protected:
	AWeapon(void);

private:
	std::string			_name;
	int					_valueAP;
	int					_damage;
};

#endif
