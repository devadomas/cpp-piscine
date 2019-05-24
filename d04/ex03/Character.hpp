#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(std::string const & name);
	virtual ~Character(void);
	Character(Character const & src);
	Character &				operator=(Character const & src);

	std::string const &		getName(void) const;
	void					equip(AMateria *);
	void					unequip(int);
	void					use(int, ICharacter &);


private:
	std::string				_name;
	int						_size;
	AMateria *				_arr[4];

	Character(void);
};

#endif
