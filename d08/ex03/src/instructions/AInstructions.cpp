#include "project.hpp"

// Constructors & destructor
AInstructions::AInstructions( void ) {}
AInstructions::AInstructions( char type ) : _type(type) {}
AInstructions::AInstructions( AInstructions const & src ) { *this = src; }
AInstructions::~AInstructions( void ) {}

// Getter
char	AInstructions::getType( void ) const { return this->_type; }

// Operator overrride
AInstructions&	AInstructions::operator=( AInstructions const & src )
{
	if (this != &src)
		this->_type = src.getType();
	return *this;
}
