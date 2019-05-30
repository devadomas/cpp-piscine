#ifndef MINDOPEN_HPP
#define MINDOPEN_HPP

#include "project.hpp"

class MindOpen {

public:

	typedef	std::vector<char>						memory;
	typedef	std::vector<char>::iterator				memory_iterator;

	typedef	std::vector<AInstructions*>				instructions;
	typedef std::vector<AInstructions*>::iterator	instructions_iterator;

	// Constructors & destructors
	MindOpen( void );
	MindOpen( MindOpen const & );
	~MindOpen( void );

	// Member functions
	void	parse( std::string const );
	void	execute( void );

private:

	// Operators override
	MindOpen&	operator=( MindOpen const & );

	// Member attributes
	memory				_memory;
	instructions		_instructions;

};

#endif
