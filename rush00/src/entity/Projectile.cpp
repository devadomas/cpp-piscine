# include "ft_retro.hpp"

// Constructors & destructor
Projectile::Projectile( void ) {}
Projectile::~Projectile( void ) {}
Projectile::Projectile( int x, int y, std::string direction ) : Entity(0, x, y), _direction(direction) {}
Projectile::Projectile( Projectile const &src ) { *this = src; }

// Operators override
Projectile&		Projectile::operator=(Projectile const &src) {
    Entity::operator=(src);
    return *this;
}

// Getters
std::string	Projectile::getDirection( void ) const { return this->_direction; }

// Member functions
void		Projectile::move( void ) {
	if (this->_direction == "up")
		this->moveUp();
	else
		this->moveDown();
}
