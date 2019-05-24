#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria
{
public:
	AMateria(std::string const & type);
	Amateria(AMateria const & src);
	~AMateria(void);
	AMateria &			operator=(AMateria const & src);

	std::string const &	getType(void) const; // Return materia type
	unsigned int 		getXP(void) const;

	virtual AMateria *	clone(void) const = 0;
	virtual void		use(ICharacter & target);

private:

protected:
	AMateria(void);
};

#endif
