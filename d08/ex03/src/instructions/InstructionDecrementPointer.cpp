#include "project.hpp"

InstructionDecrementPointer::InstructionDecrementPointer(void) : AInstructions(INSTRUCTION_DECREMENT_POINTER) {}
InstructionDecrementPointer::InstructionDecrementPointer(InstructionDecrementPointer const & src) { *this = src; }
InstructionDecrementPointer::~InstructionDecrementPointer(void) {}
InstructionDecrementPointer&	InstructionDecrementPointer::operator=(InstructionDecrementPointer const &) { return *this; }


void	InstructionDecrementPointer::execute(MindOpen::memory_iterator& mit, MindOpen::memory_iterator& beg, MindOpen::memory_iterator&, MindOpen::instructions_iterator&)
{
	if (mit != beg)
		--mit;
}
