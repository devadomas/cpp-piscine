#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name, std::string type);
	~Zombie(void);
	void		announce(void) const;
	bool		setName(std::string const name);
	bool		setType(std::string const type);
	std::string	getName(void) const;
	std::string getType(void) const;
private:
	std::string _type;
	std::string _name;
};
#endif
