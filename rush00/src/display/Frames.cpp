#include "ft_retro.hpp"

// Static variables initialization
std::string const Frames::bonuses[3] = {BONUS_SHIELD, BONUS_LIVE, BONUS_BOOST};
int			const Frames::spawn[3 * 6] = {
	F_EASY_ENEMY,F_MEDIUM_ENEMY,F_HARD_ENEMY,
	F_EASY_ENEMY_SHOT,F_MEDIUM_ENEMY_SHOT,F_HARD_ENEMY_SHOT,
	F_EASY_BOSS,F_MEDIUM_BOSS,F_HARD_BOSS,
	F_EASY_BOSS_SHOT,F_MEDIUM_BOSS_SHOT,F_HARD_BOSS_SHOT,
	F_EASY_BOSS_MOVE,F_MEDIUM_BOSS_MOVE,F_HARD_BOSS_MOVE,
	F_EASY_BONUS,F_MEDIUM_BONUS,F_HARD_BONUS
};
int			Frames::frames[6] = {-1, -1, -1, -1, -1, -1};

// Constructors & destructor
Frames::Frames( Game & game, int difficulty) : _game(game), _difficulty(difficulty), _gameDuration(0) {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	this->_startingTime = tp.tv_sec;
	this->_startingFrame = tp.tv_sec * 1000 + tp.tv_usec / 1000 - 1;
}
Frames::~Frames( void ) {}

// Getter
int		Frames::getGameDuration( void ) const { return this->_gameDuration; }

// Member functions
void	Frames::handler( void ) {

	// Update game duration
	struct timeval tp;
	gettimeofday(&tp, NULL);
	this->_gameDuration = tp.tv_sec - this->_startingTime;

	// Assess this duration in ms
	int frame = tp.tv_sec * 1000 + tp.tv_usec / 1000 - this->_startingFrame;

	// Handle enemies spawn
	this->handleEnemiesSpawn( frame );

	// Handle enemies shots
	this->handleEnemiesShoot( frame );

	// Handle boss spawn
	this->handleBossSpawn( frame );

	// Handle boss moves
	this->handleBossShoot( frame );

	// Handle boss shots
	this->handleBossMove( frame );

	// Handle bonus spawn
	this->handleBonusSpawn( frame );

	// Handle moves of ennemies, boss and projectiles
	this->handleEnemiesAndProjectilesMoves( frame );

}

void	Frames::handleEnemiesSpawn( int frame ) {
	if (frame % this->spawn[F_ENEMY * 3 + this->_difficulty] == 0 && frame != this->frames[F_ENEMY]) {
		this->frames[F_ENEMY] = frame;
		this->_game.pushEnemy();
	}
}
void	Frames::handleEnemiesShoot( int frame ) {
	if (frame % this->spawn[F_ENEMY_SHOT * 3 + this->_difficulty] == 0 && frame != this->frames[F_ENEMY_SHOT]) {
		this->frames[F_ENEMY_SHOT] = frame;
		this->_game.randomEnemyShot();
	}
}
void	Frames::handleBossSpawn( int frame ) {
	if (frame % this->spawn[F_BOSS * 3 + this->_difficulty] == 0 && frame != this->frames[F_BOSS]) {
		this->frames[F_BOSS] = frame;
		this->_game.bossSpawn();
	}
}
void	Frames::handleBossShoot( int frame ) {
	if (frame % this->spawn[F_BOSS_MOVE * 3 + this->_difficulty] == 0 && frame != this->frames[F_BOSS_MOVE]) {
		this->frames[F_BOSS_MOVE] = frame;
		this->_game.bossMove();
	}
}
void	Frames::handleBossMove( int frame ) {
	if (frame % this->spawn[F_BOSS_SHOT * 3 + this->_difficulty] == 0 && frame != this->frames[F_BOSS_SHOT]) {
		this->frames[F_BOSS_SHOT] = frame;
		this->_game.bossShot();
	}
}
void	Frames::handleBonusSpawn( int frame ) {
	if (frame % this->spawn[F_BONUS * 3 + this->_difficulty] == 0 && frame != this->frames[F_BONUS]) {
		this->frames[F_BONUS] = frame;
		this->_game.pushBonus(bonuses[rand() % 3]);
	}
}
void	Frames::handleEnemiesAndProjectilesMoves( int frame ) {
	if (frame % 500 == 0) {
		this->_game.moveAll();
		this->_game.update(this->_gameDuration);
	} else if (frame % 50 == 0) {
		this->_game.moveProjectiles();
		this->_game.update(this->_gameDuration);
	}
}
