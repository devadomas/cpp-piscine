#ifndef INSTRUCTIONINPUT_HPP
#define INSTRUCTIONINPUT_HPP

#include "project.hpp"

class InstructionInput : public AInstructions {

public:

	// Constructors & destructors
	InstructionInput( void );
	InstructionInput( InstructionInput const & );
	~InstructionInput( void );

	// Operator override
	InstructionInput	&operator=( InstructionInput const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
