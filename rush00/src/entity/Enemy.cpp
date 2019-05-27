#include "ft_retro.hpp"

// Constructors & destructor
Enemy::Enemy( void ) {}
Enemy::Enemy( int type, int x ) : Entity(ENEMY_DEFAULT_LIVES, x, ENEMY_DEFAULT_Y), _type(type) {}
Enemy::Enemy( Enemy const &src ) { *this = src; }
Enemy::~Enemy( void ) {}

// Getters
int				Enemy::getType( void ) const { return this->_type; }

// Operators override
Enemy&  		Enemy::operator=( Enemy const &src ) {
    Entity::operator=(src);
    return *this;
}

// Member functions
Projectile* 	Enemy::shoot( void ) const { return new Projectile(this->_x + ENEMY_WIDTH / 2, this->_y + ENEMY_HEIGHT, "down"); }
