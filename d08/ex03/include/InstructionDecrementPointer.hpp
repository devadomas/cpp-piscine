#ifndef INSTRUCTIONDECREMENTPOINTER_HPP
#define INSTRUCTIONDECREMENTPOINTER_HPP

#include "project.hpp"

class InstructionDecrementPointer : public AInstructions {

public:

	// Constructors & destructors
	InstructionDecrementPointer( void );
	InstructionDecrementPointer( InstructionDecrementPointer const & );
	~InstructionDecrementPointer( void );

	// Operator override
	InstructionDecrementPointer	&operator=( InstructionDecrementPointer const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
