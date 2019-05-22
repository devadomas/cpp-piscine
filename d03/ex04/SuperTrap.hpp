#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(std::string const & name);
	~SuperTrap(void);
	SuperTrap(SuperTrap const & name);
	SuperTrap			operator=(SuperTrap const & src);

private:
	SuperTrap(void);
};

#endif
