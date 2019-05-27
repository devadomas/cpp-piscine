#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "ft_retro.hpp"

class Entity {

public:

	// Constructors & destructor
	Entity( int, int, int );
	virtual ~Entity( void );

	// Getters
	int		    getX( void ) const;
	int		    getY( void ) const;
	int		    getLives( void ) const;

	// Member functions
	int		    takeDamage( void );

	void		moveDown( int );
	void		moveLeft( int );
	void		moveRight( int );
	void		moveUp( int );

	void		moveDown( void );
	void		moveLeft( void );
	void		moveRight( void );
	void		moveUp( void );

protected:

	// Constructors & destructor
	Entity( void );
	Entity( Entity const & );

	// Operator override
	Entity      &operator=( Entity const & );

	// Member attributes
	int		    _lives;
	int		    _x;
	int		    _y;

};

#endif
