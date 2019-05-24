#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string const & name);
	virtual ~FragTrap(void);
	FragTrap(FragTrap const & src);
	FragTrap &	operator=(FragTrap const & src);

	// personal attack
	void		vaulthunter_dot_exe(std::string const & target);
	// for virutal
	void		rangedAttack(std::string const & target);
	// --- for default values ---
	static int	defaultHitPoints;
	static int	defaultMaxHitPoints;
	static int	defaultRangedAttack;
	static int	defaultArmour;
protected:
	FragTrap(void);
};

#endif
