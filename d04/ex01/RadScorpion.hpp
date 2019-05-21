#ifndef RAD_SCORPION_CLASS_HPP
# define RAD_SCORPION_CLASS_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const & src);
	virtual ~RadScorpion(void);
	RadScorpion &	operator=(RadScorpion const & src);

	void			takeDamage(int damage);
};

#endif
