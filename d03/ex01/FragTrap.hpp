#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>

class FragTrap
{
public:
	FragTrap(std::string const & name);
	~FragTrap(void);
	FragTrap(FragTrap const & src);
	FragTrap &	operator=(FragTrap const & src);

	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const & target);

	int			getHP(void) const;
	int			getEnergyPoints(void) const;
	std::string	getName(void) const;

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

std::ostream & 	operator<<(std::ostream & o, FragTrap const & frag);

#endif
