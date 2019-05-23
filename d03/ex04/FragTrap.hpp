#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string const & name);
	~FragTrap(void);
	FragTrap(FragTrap const & src);
	FragTrap &	operator=(FragTrap const & src);

	// --- personal attack ---
	void		vaulthunter_dot_exe(std::string const & target);

	// --- for default values ---
	static int	defaultHitPoints;
	static int	defaultMaxHitPoints;
	static int	defaultRangedAttack;
	static int	defaultArmour;

protected:
	FragTrap(void);
};

std::ostream & 	operator<<(std::ostream & o, FragTrap const & frag);

#endif
