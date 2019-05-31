#include "project.hpp"

InstructionJumpBackward::InstructionJumpBackward(void) : AInstructions(INSTRUCTION_JUMP_BACKWARD) {}
InstructionJumpBackward::InstructionJumpBackward(InstructionJumpBackward const & src) { *this = src; }
InstructionJumpBackward::~InstructionJumpBackward(void) {}
InstructionJumpBackward&	InstructionJumpBackward::operator=(InstructionJumpBackward const &) { return *this; }

void	InstructionJumpBackward::execute(MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator& iit)
{
	int bracesCount = 0;

	do {
		if((*iit)->getType() == INSTRUCTION_JUMP_FORWARD)
			bracesCount++;
		else if((*iit)->getType() == INSTRUCTION_JUMP_BACKWARD)
			bracesCount--;
		iit--;
	} while(bracesCount);
}
