#include "ft_retro.hpp"

// Constructors & destructor
Entity::Entity( void ) {}
Entity::Entity( int lives, int x, int y ) : _lives(lives), _x(x), _y(y) {}
Entity::Entity( Entity const &src ) { *this = src; }
Entity::~Entity( void ) {}

// Operators override
Entity&		Entity::operator=( Entity const &src ) {
	if (this != & src) {
		_lives = src.getLives();
		_x = src.getX();
		_y = src.getY();
	}
    return *this;
}

// Getters
int		Entity::getX() const { return this->_x; }
int		Entity::getY() const { return this->_y; }
int		Entity::getLives() const { return this->_lives; }

// Moving functions
void	Entity::moveUp( void ) { this->_y--; }
void	Entity::moveDown( void ) { this->_y++; }
void	Entity::moveLeft( void ) { this->_x--; }
void	Entity::moveRight( void ) { this->_x++; }

void	Entity::moveUp( int jump ) { this->_y -= jump; }
void	Entity::moveDown( int jump ) { this->_y += jump; }
void	Entity::moveLeft( int jump ) { this->_x -= jump; }
void	Entity::moveRight( int jump ) { this->_x += jump; }

int		Entity::takeDamage( void ) {
	if ( this->_lives)
    	this->_lives -= 1;
    return this->_lives;
}
