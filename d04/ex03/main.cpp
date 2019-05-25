#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


int		main(void)
{
	std::cout << "--- Tests from subject ---" << std::endl;

	Ice*			ice = new Ice;
	Cure*			cure = new Cure;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(ice);
	src->learnMateria(cure);

	Character* zaz = new Character("zaz");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);

	Character* bob = new Character("bob");

	zaz->use(0, *bob);
	zaz->use(1, *bob);

	std::cout << std::endl;
	///
	std::cout << "---- More tests ----" << std::endl;
	std::cout << "Try to use wrong weapon index" << std::endl;
	zaz->use(3, *bob);
	std::cout << "Try to equip equiped AMateria" << std::endl;
	zaz->equip(tmp);
	zaz->use(2, *bob);
	std::cout << "Try to unequip non-existing AMateria" << std::endl;
	zaz->unequip(2);
	std::cout << "Try to learn materia already in sources" << std::endl;
	src->learnMateria(ice);

	// copy
	Character	zazCopy(*zaz);
	zazCopy.equip(src->createMateria("ice"));
	zazCopy.use(1, *bob);
	zazCopy.use(1, *bob);
	zazCopy.use(1, *bob);

	// assiganation
	Character	zazAssign = zazCopy;
	zazAssign.use(0, *bob);
	zazAssign.use(0, *bob);
	zazAssign.use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete zaz;
	delete src;
	delete ice;
	delete cure;
	return 0;
}
