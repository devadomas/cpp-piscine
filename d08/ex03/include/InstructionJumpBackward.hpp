#ifndef INSTRUCTIONDJUMPBACKWARD_HPP
#define INSTRUCTIONDJUMPBACKWARD_HPP

#include "project.hpp"

class InstructionJumpBackward : public AInstructions
{
public:
	InstructionJumpBackward(void);
	InstructionJumpBackward(InstructionJumpBackward const &);
	~InstructionJumpBackward(void);
	InstructionJumpBackward	&operator=(InstructionJumpBackward const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
