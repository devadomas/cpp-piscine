#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string const & name);
	~NinjaTrap(void);
	NinjaTrap(NinjaTrap const & src);
	NinjaTrap &		operator=(NinjaTrap const & src);

	void			ninjaShoebox(ClapTrap const & enemy);
	void			ninjaShoebox(FragTrap const & enemy);
	void			ninjaShoebox(ScavTrap const & enemy);
	void			ninjaShoebox(NinjaTrap const & enemy);
private:
	NinjaTrap(void);
};

#endif
