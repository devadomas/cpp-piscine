#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &) {} // impament later
MateriaSource::~MateriaSource(void) { }

MateriaSource & 	MateriaSource::operator=(MateriaSource const &)
{
	// add stuff for copy
	return *this;
}

//

void				MateriaSource::learnMateria(AMateria * m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			break ;
		}
}

AMateria *			MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	return NULL;
}
