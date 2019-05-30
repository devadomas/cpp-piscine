#ifndef INSTRUCTIONDJUMPBACKWARD_HPP
#define INSTRUCTIONDJUMPBACKWARD_HPP

#include "project.hpp"

class InstructionJumpBackward : public AInstructions {

public:

	// Constructors & destructors
	InstructionJumpBackward( void );
	InstructionJumpBackward( InstructionJumpBackward const & );
	~InstructionJumpBackward( void );

	// Operator override
	InstructionJumpBackward	&operator=( InstructionJumpBackward const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
