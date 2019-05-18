#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie();
	void announce() const;
private:
	std::string _type;
	std::string _name;
};
#endif
