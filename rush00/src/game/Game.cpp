#include "ft_retro.hpp"

Game::Game( NCurses & visual, Player & player ) : _visual(visual), _player(player) , _boss(NULL), _bonusesCounter(0), _enemiesCounter(0), _projectilesCounter(0) {}
Game::~Game( void ) {
	// Delete boss
	delete this->_boss;

	// Delete enemies
	for (int index = 0 ; index < this->_enemiesCounter ; index++)
		delete this->_enemies[index];

	// Delete projectiles
	for (int index = 0 ; index < this->_projectilesCounter ; index++)
		delete this->_projectiles[index];

	// Delete bonuses
	for (int index = 0 ; index < this->_bonusesCounter ; index++)
		delete this->_bonuses[index];
}

void 		Game::update( int duration ) {
	this->handleCollisions( duration );
	this->handleBonusesDuration( duration );
	this->_visual.clearScreen();
	this->_visual.print(this->_player);
	for (int index = 0; index < this->_bonusesCounter; index++)
		this->_visual.print(this->_bonuses[index]);
	if (this->_boss)
		this->_visual.print(this->_boss);
	for (int index = 0 ; index < this->_enemiesCounter ; index++)
		this->_visual.print(this->_enemies[index]);
	for (int index = 0 ; index < this->_projectilesCounter ; index++)
		this->_visual.print(this->_projectiles[index]);
	this->_visual.print(this->_player, duration);
	mvprintw(this->_visual.getWindowHeight() - 2, 1, " X | Y ");
	mvprintw(this->_visual.getWindowHeight() - 1, 1, "%03d|%03d", this->_player.getX(), this->_player.getY());
	mvprintw(1 , 1 , "Bonuses: %d", this->_bonusesCounter);
	mvprintw(2 , 1 , "Enemies: %d", this->_enemiesCounter);
	mvprintw(3 , 1 , "Projectiles: %d", this->_projectilesCounter);
}

// Shooting
void		Game::bossShot( void ) {
	if (this->_projectilesCounter + 1 == GAME_MAX_PROJECTILES || !this->_boss)
		return ;
	this->_projectiles[this->_projectilesCounter] = this->_boss->shootA();
	this->_projectilesCounter++;
	this->_projectiles[this->_projectilesCounter] = this->_boss->shootB();
	this->_projectilesCounter++;
}

void		Game::playerShot( void ) {
	if (this->_projectilesCounter == GAME_MAX_PROJECTILES)
		return ;
	this->_projectiles[this->_projectilesCounter] = this->_player.shoot();
	this->_projectilesCounter++;
}

void		Game::randomEnemyShot( void ) {
	if (this->_projectilesCounter == GAME_MAX_PROJECTILES || this->_enemiesCounter == 0)
		return ;
	this->_projectiles[this->_projectilesCounter] = this->_enemies[rand() % this->_enemiesCounter]->shoot();
	this->_projectilesCounter++;
}

// Spawn
void		Game::pushEnemy( void ) {
	if (this->_enemiesCounter == GAME_MAX_ENEMIES)
		return ;

	// Get position of new enemy
	int		x = rand() % (this->_visual.getWindowWidth() - ENEMY_WIDTH);

	// Remove any projectile that could cause problem
	for (int index = 0 ; index < this->_projectilesCounter ; index++) {
		int projectileX = this->_projectiles[index]->getX();
		int projectileY = this->_projectiles[index]->getY();
		if (projectileY < ENEMY_HEIGHT + 1 && projectileX >= x && projectileX <= x + ENEMY_WIDTH) {
			this->deleteProjectile( index );
			index--;
		}
	}
	this->_enemies[this->_enemiesCounter] = new Enemy(rand() % 4, x);
	this->_enemiesCounter++;
}

void		Game::pushBonus( std::string type ) {
	if (this->_bonusesCounter == GAME_MAX_BONUSES)
		return ;

	int x = rand() % this->_visual.getWindowWidth();
	int y = rand() % this->_visual.getWindowHeight();

	this->_bonuses[this->_bonusesCounter] = new Bonus(x, y, type);
	this->_bonusesCounter++;
}

void		Game::bossSpawn( void ) {

	if (this->_boss != NULL)
		return ;

	// Delete all projectiles
	for (int index = 0 ; index < this->_projectilesCounter ; index++) {
		delete this->_projectiles[index];
		this->_projectiles[index] = NULL;
	}

	// Delete all enemies
	for (int index = 0 ; index < this->_enemiesCounter ; index++) {
		delete this->_enemies[index];
		this->_enemies[index] = NULL;
	}

	this->_projectilesCounter = 0;
	this->_enemiesCounter = 0;
	this->_boss = new Boss((this->_visual.getWindowWidth() - BOSS_WIDTH) / 2);
}

void		Game::handleBonusesDuration( int duration ) {
	int		shield = this->_player.hasShield();
	int		xpBoost = this->_player.hasBoost();

	if (shield)
		mvprintw(6,1, "Shield duration left: %d vs duration %d", shield, duration);
	if (xpBoost)
		mvprintw(6,1, "xpBoost duration left: %d vs duration %d", xpBoost, duration);
	if (shield && shield < duration)
		this->_player.unsetShield();
	if (xpBoost && xpBoost < duration)
		this->_player.unsetBoost();
}

void		Game::handleCollisions( int duration ) {

    int     overflowWidth = 0;
	bool    rightOverflow = false;
	int		playerX = this->_player.getX();
	int		playerY = this->_player.getY();
	int		playerWidth = this->_player.getPlayerDisplayWidth();
	int		playerHeight = this->_player.getPlayerDisplayHeight();

	// Verify player overflow
    if (playerX + playerWidth >= this->_visual.getWindowWidth()) {
        rightOverflow = true;
        overflowWidth = playerX + playerWidth - this->_visual.getWindowWidth();
    }

	// Handle bonuses
	for (int index = 0 ; index < this->_bonusesCounter ; index++) {
		int		x = this->_bonuses[index]->getX();
		int		y = this->_bonuses[index]->getY();
		if ((y >= playerY && y <= playerY + playerHeight && x >= playerX && x <= playerX + playerWidth) ||
		(rightOverflow && y >= playerY && y <= playerY + playerHeight && x <= overflowWidth)) {
			std::string	type = this->_bonuses[index]->getType();
			if (type == BONUS_SHIELD)
				this->_player.setShield( duration );
			else if (type == BONUS_BOOST)
				this->_player.setBoost( duration );
			else
				this->_player.addLives();
			this->deleteBonus(index);
			index--;
		}
	}

	// Handle projectiles
	for (int i = 0 ; i < this->_projectilesCounter ; i ++) {

		bool	someoneGetShot = false;

		int		x = this->_projectiles[i]->getX();
		int		y = this->_projectiles[i]->getY();

		if (y < 1 || y >= this->_visual.getWindowHeight()) {
			this->deleteProjectile(i);
			someoneGetShot = true;
			i--;
		}

		// Projectile vs Boss
		if (this->_boss && !someoneGetShot) {
			int		bossX = this->_boss->getX();
			int		bossY = this->_boss->getY();

			if (y >= bossY && y <= bossY + BOSS_HEIGHT && x >= bossX && x <= bossX + BOSS_WIDTH) {
				someoneGetShot = true;
				if (this->_boss->takeDamage() == 0) {
					delete this->_boss;
					this->_boss = NULL;
					this->_player.giveScore(SCORE_BOSS_SHOT);
				} else
						this->_player.giveScore(SCORE_BOSS_DOWN);
				this->deleteProjectile(i);
				i--;
			}
		}

		// Projectile vs Enemies
		if (!someoneGetShot && this->_projectiles[i]->getDirection() == "up")
			for (int j = 0 ; j < this->_enemiesCounter ; j++) {
				int		enemyX = this->_enemies[j]->getX();
				int		enemyY = this->_enemies[j]->getY();
				if (y >= enemyY && y <= enemyY + ENEMY_HEIGHT && x >= enemyX && x <= enemyX + ENEMY_WIDTH) {
					someoneGetShot = true;
					if (this->_enemies[j]->takeDamage() == 0) {
						this->_player.giveScore(SCORE_ENEMY_DOWN);
						this->deleteEnemy(j);
					} else
						this->_player.giveScore(SCORE_ENEMY_SHOT);
					this->deleteProjectile(i);
					i--;
					break;
				}
			}

		// Projectile vs player
		if (!someoneGetShot && ( (y >= playerY && y <= playerY + playerHeight && x >= playerX && x <= playerX + playerWidth) ||
		(rightOverflow && y >= playerY && y <= playerY + playerHeight && x <= overflowWidth ) ) ) {
			this->_player.takeDamage();
			someoneGetShot = true;
			this->deleteProjectile(i);
			i--;
		}
	}

	// Handle collisions between Boss vs Player
	if (this->_boss) {
		int		bossX = this->_boss->getX();
		int		bossY = this->_boss->getY();
		int		bossWMax = bossX + BOSS_WIDTH;
	    int		bossHmax = bossY + BOSS_HEIGHT;

    	if ( (bossY <= playerY + playerHeight && bossHmax >= playerY + playerHeight && ((bossX <= playerX + playerHeight && bossWMax >= playerX ) || (bossWMax >= playerX && bossX <= playerX + playerWidth))) ||
		(bossY <= playerY + playerHeight && bossHmax >= playerY && ((bossX <= playerX + playerHeight && bossWMax >= playerX ) || (bossWMax >= playerX && bossX <= playerX + playerWidth))) ||
		(rightOverflow && (bossY <= playerY + playerHeight && bossHmax >= playerY + playerHeight && ((bossX <= overflowWidth && bossWMax >= 0 ) || (bossWMax >= 0 && bossX <= overflowWidth)))) ||
		(rightOverflow && (bossY <= playerY + playerHeight && bossHmax >= playerY && ((bossX <= overflowWidth && bossWMax >= 0 ) || (bossWMax >= 0 && bossX <= overflowWidth)))) ) {			if (this->_boss->takeDamage() == 0) {
				delete this->_boss;
				this->_boss = NULL;
			}
			this->_player.takeDamage();
		}
	}

	// Handle collisions between Enemies vs Player
	for (int index = 0 ; index < this->_enemiesCounter ; index++) {
		int		enemyX = this->_enemies[index]->getX();
		int		enemyY = this->_enemies[index]->getY();
		int		enemyWMax = enemyX + ENEMY_WIDTH;
	    int		enemyHmax = enemyY + ENEMY_HEIGHT;

		if (enemyY >= this->_visual.getWindowHeight())
			this->deleteEnemy(index--);
	    else if ( (enemyY <= playerY + playerHeight && enemyHmax >= playerY + playerHeight && ((enemyX <= playerX + playerHeight && enemyWMax >= playerX ) || (enemyWMax >= playerX && enemyX <= playerX + playerWidth))) ||
		(enemyY <= playerY + playerHeight && enemyHmax >= playerY && ((enemyX <= playerX + playerHeight && enemyWMax >= playerX ) || (enemyWMax >= playerX && enemyX <= playerX + playerWidth))) ||
		(rightOverflow && (enemyY <= playerY + playerHeight && enemyHmax >= playerY + playerHeight && ((enemyX <= overflowWidth && enemyWMax >= 0 ) || (enemyWMax >= 0 && enemyX <= overflowWidth)))) ||
		(rightOverflow && (enemyY <= playerY + playerHeight && enemyHmax >= playerY && ((enemyX <= overflowWidth && enemyWMax >= 0 ) || (enemyWMax >= 0 && enemyX <= overflowWidth))))  ) {
			this->deleteEnemy(index);
			this->_player.giveScore(SCORE_ENEMY_DOWN);
			this->_player.giveScore(SCORE_ENEMY_DOWN);
			this->_player.takeDamage();
			index--;
		}
	}
}

// Private Utils
void		Game::deleteProjectile( int index ) {
	if (index < 0 || index >= this->_projectilesCounter)
		return ;

	delete this->_projectiles[index];
	this->_projectiles[index] = NULL;

	this->_projectilesCounter--;
	for (int idx = index ; idx < this->_projectilesCounter ; idx++)
		this->_projectiles[idx] = this->_projectiles[idx + 1];

	if (this->_projectilesCounter < GAME_MAX_PROJECTILES)
		this->_projectiles[this->_projectilesCounter] = NULL;
}
void		Game::deleteEnemy( int index ) {
	if (index < 0 || index >= this->_enemiesCounter)
		return ;

	delete this->_enemies[index];
	this->_enemies[index] = NULL;
	this->_enemiesCounter--;

	for (int idx = index ; idx < this->_enemiesCounter ; idx++)
		this->_enemies[idx] = this->_enemies[idx + 1];

	if (this->_enemiesCounter < GAME_MAX_ENEMIES)
		this->_enemies[this->_enemiesCounter] = NULL;
}
void		Game::deleteBonus( int index ) {
	if (index < 0 || index >= this->_bonusesCounter)
		return ;

	delete this->_bonuses[index];
	this->_bonuses[index] = NULL;

	this->_bonusesCounter--;
	for (int idx = index ; idx < this->_bonusesCounter ; idx++)
		this->_bonuses[idx] = this->_bonuses[idx + 1];

	if (this->_bonusesCounter < GAME_MAX_BONUSES)
		this->_bonuses[this->_bonusesCounter] = NULL;
}
void		Game::moveAll( void ) {
	this->moveProjectiles();
	this->moveEnemies();

}
void		Game::moveProjectiles( void ) {
	for (int index = 0 ; index < this->_projectilesCounter ; index++)
		this->_projectiles[index]->move();
}
void		Game::moveEnemies( void ) {
	for (int index = 0 ; index < this->_enemiesCounter ; index++)
		this->_enemies[index]->moveDown();
}

void		Game::bossMove(void) {
	if (!this->_boss)
		return ;

	int playerX = this->_player.getX();
	int	bossX = this->_boss->getX();

	if (playerX > bossX && bossX + BOSS_WIDTH < this->_visual.getWindowWidth())
		this->_boss->moveRight(BOSS_DEFAULT_MOVE);
	else if (bossX > 0)
		this->_boss->moveLeft(BOSS_DEFAULT_MOVE);
}
