#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	virtual ~AMateria(void);
	AMateria &			operator=(AMateria const & src);

	std::string const &	getType(void) const; // Return materia type
	unsigned int 		getXP(void) const;

	virtual AMateria *	clone(void) const = 0;
	virtual void		use(ICharacter & target);

private:
	unsigned int		xp_;
	std::string			_type;


protected:
	AMateria(void);
	void			setType(std::string const & type);
	void			setXP(int xp);
};

#endif
