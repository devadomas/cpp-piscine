#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter
{
public:
	virtual ~ICharacter(void) {}
	virtual std::string const & getName(void) const = 0;
	virtual void				equip(AMateria * m) = 0;
	virutal void				unequip(int idx) = 0;
	virutal void				use(int idx, ICharacter & target) = 0;
};

#endif
