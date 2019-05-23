#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(std::string const & name);
	virtual ~NinjaTrap(void);
	NinjaTrap(NinjaTrap const & src);
	NinjaTrap &		operator=(NinjaTrap const & src);

	void			ninjaShoebox(ClapTrap const & enemy);
	void			ninjaShoebox(FragTrap const & enemy);
	void			ninjaShoebox(ScavTrap const & enemy);
	void			ninjaShoebox(NinjaTrap const & enemy);

	// --- shared ---
	void			meleeAttack(std::string const & target);
	// for default values
	static int		defaultEnergyPoints;
	static int		defaultMaxEnergyPoints;
	static int		defaultMeleeAttack;

protected:
	NinjaTrap(void);
};

#endif
