#ifndef		SCAVTRAP_CLASS_CPP
# define	SCAVTRAP_CLASS_CPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const & name);
	~ScavTrap(void);
	ScavTrap(ScavTrap const & src);
	ScavTrap &	operator=(ScavTrap const & src);

	// personal attack
	void		challengeNewcomer(std::string const & target);

private:
	ScavTrap(void);
};

std::ostream & 	operator<<(std::ostream & o, ScavTrap const & scav);

#endif
