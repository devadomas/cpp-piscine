#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "ft_retro.hpp"

class Projectile : public Entity {

public:
	
	// Constructors & destructor
	Projectile( int, int, std::string );
	virtual ~Projectile( void );

	// Getters
	std::string	getDirection( void ) const;

	// Member functions
	void		move( void );


private:

	// Constructors & destructor
	Projectile( void );
	Projectile( Projectile const & );

	// Member attributes
	std::string		_direction;

	// Operator override
	Projectile  &operator=( Projectile const & );
};

#endif
