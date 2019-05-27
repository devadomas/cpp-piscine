#include "ft_retro.hpp"

// Constructors & destructor
Boss::Boss( void ) {}
Boss::Boss( Boss const & src ) { *this = src; }
Boss::Boss( int x ) : Entity(BOSS_DEFAULT_LIVES, x, BOSS_DEFAULT_Y) {}
Boss::~Boss( void ) {}

// Operators override
Boss&   		Boss::operator=(Boss const &src) {
    Entity::operator=(src);
    return *this;
}

// Member functions
Projectile*		Boss::shootA( void ) const { return new Projectile(this->_x + 4, this->_y + BOSS_HEIGHT, "down"); }
Projectile*		Boss::shootB( void ) const { return new Projectile(this->_x + 13, this->_y + BOSS_HEIGHT, "down"); }
