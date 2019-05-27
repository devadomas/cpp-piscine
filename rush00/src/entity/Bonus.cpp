#include "ft_retro.hpp"

// Constructors & destructor
Bonus::Bonus( void ) { }
Bonus::~Bonus( void ) { }
Bonus::Bonus( int x, int y, std::string type ): Entity(0, x, y), _type(type) { }

// Operators override
Bonus &			Bonus::operator=( Bonus const & src ) {
	Entity::operator=(src);
	if (this != &src)
		this->_type = src.getType();
	return *this;
}

// Getters & setters
void			Bonus::setType( std::string const & type ) { this->_type = type; }
std::string		Bonus::getType( void ) const { return this->_type; }
