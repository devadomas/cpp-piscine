#ifndef INSTRUCTIONDECREMENTBYTE_HPP
#define INSTRUCTIONDECREMENTBYTE_HPP

#include "project.hpp"

class InstructionDecrementByte : public AInstructions {

public:

	// Constructors & destructors
	InstructionDecrementByte( void );
	InstructionDecrementByte( InstructionDecrementByte const & );
	~InstructionDecrementByte( void );

	// Operator override
	InstructionDecrementByte	&operator=( InstructionDecrementByte const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
