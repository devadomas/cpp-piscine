#ifndef INSTRUCTIONINCREMENTBYTE_HPP
#define INSTRUCTIONINCREMENTBYTE_HPP

#include "project.hpp"

class InstructionIncrementByte : public AInstructions {

public:

	// Constructors & destructors
	InstructionIncrementByte( void );
	InstructionIncrementByte( InstructionIncrementByte const & );
	~InstructionIncrementByte( void );

	// Operator override
	InstructionIncrementByte	&operator=( InstructionIncrementByte const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
