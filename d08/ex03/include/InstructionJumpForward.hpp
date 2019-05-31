#ifndef INSTRUCTIONJUMPFORWARD_HPP
#define INSTRUCTIONJUMPFORWARD_HPP

#include "project.hpp"

class InstructionJumpForward : public AInstructions
{
public:
	InstructionJumpForward(void);
	InstructionJumpForward(InstructionJumpForward const &);
	~InstructionJumpForward(void);
	InstructionJumpForward	&operator=(InstructionJumpForward const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
