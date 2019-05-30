#ifndef AINSTRUCTIONS_HPP
#define AINSTRUCTIONS_HPP

#include "project.hpp"

class AInstructions {

public:

	typedef	std::vector<char>::iterator				memory_iterator;
	typedef std::vector<AInstructions*>::iterator	instructions_iterator;

	// Constructors & destructor
	AInstructions( AInstructions const & );
	virtual ~AInstructions( void );

	// Operator overrride
	AInstructions&	operator=( AInstructions const & );

	// Getter
	char	getType( void ) const;

	// Member function
	virtual void	execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& ) = 0;

protected:

	// Constructors & destructor
	AInstructions( void );
	AInstructions( char );

private:

	// Member attributes
	char	_type;

};

#endif
