#include "project.hpp"

InstructionJumpForward::InstructionJumpForward(void) : AInstructions(INSTRUCTION_JUMP_FORWARD) {}
InstructionJumpForward::InstructionJumpForward(InstructionJumpForward const & src) { *this = src; }
InstructionJumpForward::~InstructionJumpForward(void) {}
InstructionJumpForward&	InstructionJumpForward::operator=(InstructionJumpForward const &) { return *this; }

void	InstructionJumpForward::execute(MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator& iit)
{
	int bracesCount = 1;

	if (!(*mit))
		do {
			iit++;
			if((*iit)->getType() == INSTRUCTION_JUMP_FORWARD)
				bracesCount++;
			else if((*iit)->getType() == INSTRUCTION_JUMP_BACKWARD)
				bracesCount--;
		} while(bracesCount);
}
