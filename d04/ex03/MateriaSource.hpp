#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource(void);
	virtual ~MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	MateriaSource &			operator=(MateriaSource const & src);

	// fun stuff
	void					learnMateria(AMateria *);
	AMateria *				createMateria(std::string const & type);

private:
	std::string		_type;
	AMateria *		_materia[4];
};

#endif
