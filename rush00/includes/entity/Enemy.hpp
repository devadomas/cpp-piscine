#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ft_retro.hpp"

class Enemy : public Entity {

public:

	// Constructors & destructor
	Enemy( int, int );
	virtual ~Enemy( void );

	// Getters
	int			getType( void ) const;
	
	// Member function
	Projectile*	shoot( ) const;

private:

	// Constructors & destructor
	Enemy( void );
	Enemy( Enemy const & );

	// Operator override
	Enemy       &operator=( Enemy const & );

	// Member attributes
	int		_type;

};

#endif
