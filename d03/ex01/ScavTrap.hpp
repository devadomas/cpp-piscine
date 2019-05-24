#ifndef		SCAVTRAP_CPP
# define	SCAVTRAP_CPP

class ScavTrap
{
public:
	ScavTrap(std::string const & name);
	~ScavTrap(void);
	ScavTrap(ScavTrap const & src);
	ScavTrap &	operator=(ScavTrap const & src);

	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer(std::string const & target);

	int			getHP(void) const;
	int			getEnergyPoints(void) const;
	std::string	getName(void) const;
	int			getMaxHP(void) const;
	int			getMaxEnergyPoints(void) const;
	int			getLevel(void) const;
	int			getMeleeDamage(void) const;
	int			getRangedAttack(void) const;
	int			getArmour(void) const;

private:
	int			_valueHit;
	int			_maxHit;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	int			_meleeDamage;
	int			_rangedAttack;
	int			_armor;

	ScavTrap(void);
};

std::ostream & 	operator<<(std::ostream & o, ScavTrap const & scav);

#endif
