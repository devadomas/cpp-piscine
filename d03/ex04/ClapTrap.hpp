#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:

	ClapTrap(
		std::string const & name,
		int					valueHit,
		int					maxHit,
		int					energyPoints,
		int					maxEnergyPoints,
		int					level,
		int					meleeDamage,
		int					rangedAttack,
		int					armor,
		std::string const &	type
	);

	virtual ~ClapTrap(void);
	ClapTrap(ClapTrap const & src);
	ClapTrap &	operator=(ClapTrap const & src);

	virtual void		rangedAttack(std::string const & target);
	virtual void		meleeAttack(std::string const & target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int			getHP(void) const;
	int			getMaxHP(void) const;
	int			getEnergyPoints(void) const;
	int			getMaxEnergyPoints(void) const;
	int			getLevel(void) const;
	int			getMeleeDamage(void) const;
	int			getRangedAttack(void) const;
	int			getArmour(void) const;
	std::string	getType(void) const;

	void		setName(std::string const & name);
	void		setHP(int value);
	void		setEnergyPoints(int value);
	void		setMaxHP(int value);
	void		setMaxEnergyPoints(int value);
	void		setLevel(int value);
	void		setMeleeDamage(int value);
	void		setRangedAttack(int value);
	void		setArmour(int value);
	void		setType(std::string const & type);

protected:
	ClapTrap(void);

	std::string	_name;
	int			_valueHit;
	int			_maxHit;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	int			_meleeDamage;
	int			_rangedAttack;
	int			_armor;

private:
	std::string	_type;

};

std::ostream & 	operator<<(std::ostream & o, ClapTrap const & clap);

#endif
