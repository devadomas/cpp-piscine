#ifndef INSTRUCTIONJUMPFORWARD_HPP
#define INSTRUCTIONJUMPFORWARD_HPP

#include "project.hpp"

class InstructionJumpForward : public AInstructions {

public:

	// Constructors & destructors
	InstructionJumpForward( void );
	InstructionJumpForward( InstructionJumpForward const & );
	~InstructionJumpForward( void );

	// Operator override
	InstructionJumpForward	&operator=( InstructionJumpForward const & );

	// Member functions
	virtual void execute( memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator& );
};

#endif
