#include "ft_retro.hpp"

// Constructors & destructor
Player::Player( int width, int height ) :
	_lives(GAME_START_LIVES),
	_x(width / 2 - DEFAULT_PLAYER_DISPLAY_WIDTH),
	_y(height - DEFAULT_PLAYER_DISPLAY_HEIGHT - 2),
	_score(0),
	_boost(0),
	_shield(0),
	_screenHeight(height),
	_screenWidth(width),
	_playerWidth(DEFAULT_PLAYER_WIDTH),
	_playerHeight(DEFAULT_PLAYER_HEIGHT),
	_playerDisplayWidth(DEFAULT_PLAYER_DISPLAY_WIDTH),
	_playerDisplayHeight(DEFAULT_PLAYER_DISPLAY_HEIGHT) { }
Player::~Player( void ) {}
Player::Player( Player const & src ) { *this = src; }

// Operator override
Player &		Player::operator=( Player const &src ) {
	if (this != &src) {
		this->_lives = src._lives;
		this->_x = src._x;
		this->_y = src._y;
		this->_score = src._score;
		this->_boost = src._boost;
		this->_shield = src._shield;
		this->_screenWidth = src._screenWidth;
		this->_screenHeight = src._screenHeight;
		this->_playerWidth = src._playerWidth;
		this->_playerHeight = src._playerHeight;
		this->_playerDisplayWidth = src._playerWidth;
	}
	return *this;
}

// Member functions
Projectile* Player::shoot( void ) const {
	if (this->_x > (this->_screenWidth - this->_playerDisplayWidth / 2) && this->_x <= this->_screenWidth)
		return new Projectile(this->_playerDisplayWidth / 2 - (this->_screenWidth - this->_x), this->_y - 1, "up");
	return new Projectile(this->_x + this->_playerDisplayWidth / 2, this->_y - 1, "up");
}

// getters
int			Player::getLives( void ) const { return this->_lives; }
int			Player::getX( void ) const { return this->_x; }
int			Player::getY( void ) const { return this->_y; }
int			Player::getScore( void ) const { return this->_score; }
int			Player::getScreenWidth( void ) const { return this->_screenWidth; }
int			Player::getScreenHeight( void ) const { return this->_screenHeight; }
int			Player::getPlayerWidth( void ) const { return this->_playerWidth; }
int			Player::getPlayerHeight( void ) const { return this->_playerHeight; }
int			Player::getPlayerDisplayWidth( void ) const { return this->_playerDisplayWidth; }
int			Player::getPlayerDisplayHeight( void ) const { return this->_playerDisplayHeight; }

// setters
void		Player::setLives( int n ) { this->_lives = n; }
void		Player::setX( int x ) { this->_x = x; }
void		Player::setY( int y ) { this->_y = y; }
void		Player::setScore( int score ) { this->_score = score; }
void 		Player::setScreenWidth( int w ) { this->_screenWidth = w; }
void		Player::setScreenHeight( int h ) { this->_screenHeight = h; }
void		Player::setPlayerWidth( int w ) { this->_playerWidth = w; }
void		Player::setPlayerHeight( int h ) { this->_playerHeight = h; }
void		Player::setPlayerDisplayWidth( int w ) { this->_playerDisplayWidth = w; }
void		Player::setPlayerDisplayHeight( int h ) { this->_playerDisplayHeight = h; }

// fun stuff
void 		Player::addLives( void ) { this->_lives += (this->_lives < GAME_MAX_LIVES) ? 1 : 0; }
void		Player::giveScore( int score ) { this->_score += score * (this->_boost ? PLAYER_DEFAULT_SCORE_MULT : 1); }

void		Player::takeDamage( void ) { this->_lives -= (this->_shield) ? 0 : 1; }

void		Player::moveUp( void ) { this->_y = (this->_y <= 0 ? 0 : this->_y - PLAYER_MOVE_VERTICAL); }
void		Player::moveDown( void ) { this->_y = (this->_y + this->_playerDisplayHeight >= this->_screenHeight) ? this->_screenHeight - this->_playerDisplayHeight : this->_y + PLAYER_MOVE_VERTICAL; }
void		Player::moveLeft( void ) { this->_x = (this->_x - PLAYER_MOVE_HORIZONTAL < 0) ? this->_screenWidth + (this->_x - PLAYER_MOVE_HORIZONTAL ) : this->_x - PLAYER_MOVE_HORIZONTAL; }
void		Player::moveRight( void ) { this->_x = (this->_x + PLAYER_MOVE_HORIZONTAL >= this->_screenWidth) ? 0 : this->_x + PLAYER_MOVE_HORIZONTAL; }

int 		Player::hasBoost( void ) const { return this->_boost; }
void		Player::setBoost( int duration ) { this->_boost = duration + PLAYER_BOOST_DURATION; }
void		Player::unsetBoost( void ) { this->_boost = 0; }

int 		Player::hasShield( void ) const { return this->_shield; }
void		Player::setShield( int duration ) { this->_shield = duration + PLAYER_SHIELD_DURATION; }
void		Player::unsetShield( void ) { this->_shield = 0; }
