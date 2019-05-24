#ifndef		SCAVTRAP_CLASS_CPP
# define	SCAVTRAP_CLASS_CPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string const & name);
	virtual ~ScavTrap(void);
	ScavTrap(ScavTrap const & src);
	ScavTrap &	operator=(ScavTrap const & src);

	// personal attack
	void		challengeNewcomer(std::string const & target);

protected:
	ScavTrap(void);
};

#endif
