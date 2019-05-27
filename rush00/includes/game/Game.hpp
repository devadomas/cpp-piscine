#ifndef GAME_HPP
#define GAME_HPP

#include "ft_retro.hpp"

class NCurses;
class Player;
class Enemy;
class Boss;
class Projectile;
class Bonus;

class Game {

public:

	// Constructor and destructor
	Game( NCurses &, Player & );
	virtual ~Game( void );

	// Utils
	void		update( int );
	void		moveAll( void );
	void		moveProjectiles( void );
	void		moveEnemies( void );
	void		bossMove(void);

	// Shot
	void		bossShot( void );
	void		playerShot( void );
	void		randomEnemyShot( void );
	void		randomBossShot( void );

	// Creation/deletion of entities
	void		pushEnemy( void );
	void		pushBonus( std::string );
	void		bossSpawn( void );


private:

	// Member attributes
	NCurses&		_visual;

	Player&			_player;
	Boss*			_boss;

	int				_bonusesCounter;
	Bonus*			_bonuses[GAME_MAX_BONUSES];

	int				_enemiesCounter;
	Enemy*			_enemies[GAME_MAX_ENEMIES];

	int				_projectilesCounter;
	Projectile*		_projectiles[GAME_MAX_PROJECTILES];

	void			handleBonusesDuration( int );
	void			handleCollisions( int );
	void			deleteProjectile( int );
	void			deleteEnemy( int );
	void			deleteBonus( int );


	// Constructor and destructor
	Game( void );
	Game( Game const & );

	// Opearator override
	Game &	operator=( Game const & );

};

#endif
