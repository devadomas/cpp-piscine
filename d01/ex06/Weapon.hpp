#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <string>

class Weapon
{
public:
	Weapon(std::string const type);
	~Weapon(void);
	std::string		getType(void) const;
	bool			setType(std::string const type);
private:
	std::string		_type;
};

#endif
