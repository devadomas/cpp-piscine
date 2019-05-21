#ifndef SUPER_MUTANT_CLASS_HPP
# define SUPER_MUTANT_CLASS_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const & src);
	virtual ~SuperMutant(void);
	SuperMutant &		operator=(SuperMutant const & src);

	void		takeDamage(int damage);
};

#endif
