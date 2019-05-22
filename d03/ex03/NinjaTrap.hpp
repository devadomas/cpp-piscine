#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string const & name);
	~NinjaTrap(void);
	NinjaTrap(NinjaTrap const & src);
	NinjaTrap &		operator=(NinjaTrap const & src);

private:
	NinjaTrap(void);
};

#endif
