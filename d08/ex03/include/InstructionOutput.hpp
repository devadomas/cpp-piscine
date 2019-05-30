#ifndef INSTRUCTIONOUTPUT_HPP
#define INSTRUCTIONOUTPUT_HPP

#include "project.hpp"

class InstructionOutput : public AInstructions {

public:

	// Constructors & destructors
	InstructionOutput( void );
	InstructionOutput( InstructionOutput const & );
	~InstructionOutput( void );

	// Operator override
	InstructionOutput	&operator=( InstructionOutput const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
