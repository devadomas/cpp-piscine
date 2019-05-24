#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string const & name);
	~FragTrap(void);
	FragTrap(FragTrap const & src);
	FragTrap &	operator=(FragTrap const & src);

	// personal attack
	void		vaulthunter_dot_exe(std::string const & target);

private:
	FragTrap(void);
};

std::ostream & 	operator<<(std::ostream & o, FragTrap const & frag);

#endif
