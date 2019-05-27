#ifndef BOSS_HPP
# define BOSS_HPP

# include "ft_retro.hpp"

class Boss : public Entity {

public:

	// Constructors & destructor
	Boss( int );
	virtual ~Boss( void );

	// Member functions
	Projectile*  shootA( void ) const;
	Projectile*  shootB( void ) const;

private:

	// Constructors & destructor
	Boss( void );
	Boss( Boss const & );

	// Operator override
	Boss        &operator=( Boss const & );

};

#endif
