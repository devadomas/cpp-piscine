#ifndef FRAMES_HPP
#define FRAMES_HPP

#include "ft_retro.hpp"

class Game;

class Frames {

public:

	// Constructors & destructor
	Frames( Game &, int );
	Frames( Frames const & );
	~Frames( void );

	// Getters
	int		getGameDuration( void ) const;

	// Member functions
	void	handler( void );
	void	handleEnemiesSpawn( int frame );
	void	handleEnemiesShoot( int frame );
	void	handleBossSpawn( int frame );
	void	handleBossShoot( int frame );
	void	handleBossMove( int frame );
	void	handleBonusSpawn( int frame );
	void	handleEnemiesAndProjectilesMoves( int frame );

private:

	// Constructors & destructor
	Frames( void );

	// Operator override
	Frames &	operator=( Frames const & );

	// Member attributes
	Game&					_game;
	int						_difficulty;
	int						_gameDuration;
	int						_startingTime;
	long int				_startingFrame;

	static int					frames[6];
	static const int			spawn[3 * 6];
	static const std::string	bonuses[3];
};

#endif
