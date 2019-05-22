#ifndef		SCAVTRAP_CLASS_CPP
# define	SCAVTRAP_CLASS_CPP

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

	int			getHP(void) const;
	int			getEnergyPoints(void) const;
	std::string	getName(void) const;
	void		challengeNewcomer(std::string const & target);

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
};

std::ostream & 	operator<<(std::ostream & o, ScavTrap const & scav);

#endif
