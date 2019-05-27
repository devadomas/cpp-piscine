#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ft_retro.hpp"

class Player {

public:

	// Constructor.s & destructor
	Player( int, int ); // _screenWidth ; _screenHeight
	virtual ~Player( void );

	// Member functions
	Projectile*		shoot( void ) const;

	// Getters
	int			getLives( void ) const;
	int			getSize( void ) const;
	int			getX( void ) const;
	int			getY( void ) const;
	int			getScore( void ) const;
	int			getScreenWidth( void ) const;
	int			getScreenHeight( void ) const;
	int			getPlayerWidth( void ) const;
	int			getPlayerHeight( void ) const;
	int			getPlayerDisplayWidth( void ) const;
	int			getPlayerDisplayHeight( void ) const;
	int			getDurationBoost( void ) const;
	int			getDurationShield( void ) const;

	// Setters
	void		setLives( int );
	void		setSize( int );
	void		setX( int );
	void		setY( int );
	void		setScore( int );
	void		setScreenWidth( int );
	void		setScreenHeight( int );
	void		setPlayerWidth( int );
	void		setPlayerHeight( int );
	void		setPlayerDisplayWidth( int );
	void		setPlayerDisplayHeight( int );
	void		setDurationBoost( int );
	void		setDurationShield( int );

	// Member functions
	void		setBoost( int );
	void		setShield( int );
	int			hasBoost( void ) const;
	int			hasShield( void ) const;
	void		unsetBoost( void );
	void		unsetShield( void );
	void		addLives( void );
	void		giveScore( int );
	void		takeDamage( void );
	void		moveUp( void );
	void		moveDown( void );
	void		moveLeft( void );
	void		moveRight( void );

private:

	// Member attributes (player relative)
	int		_lives;
	int		_x;
	int		_y;
	int		_score;
	int		_boost;
	int		_shield;

	// Member attributes (display relative)
	int		_screenHeight;
	int		_screenWidth;
	int		_playerWidth;
	int		_playerHeight;
	int		_playerDisplayWidth;
	int		_playerDisplayHeight;

	// Constructors & destructor
	Player( void );
	Player( Player const & );

	// Operator override
	Player &	operator=( Player const & );
};

#endif
