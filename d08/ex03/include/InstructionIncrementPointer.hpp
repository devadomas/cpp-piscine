#ifndef INSTRUCTIONINCREMENTPOINTER_HPP
#define INSTRUCTIONINCREMENTPOINTER_HPP

#include "project.hpp"

class InstructionIncrementPointer : public AInstructions {

public:

	// Constructors & destructors
	InstructionIncrementPointer( void );
	InstructionIncrementPointer( InstructionIncrementPointer const & );
	~InstructionIncrementPointer( void );

	// Operator override
	InstructionIncrementPointer	&operator=( InstructionIncrementPointer const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
