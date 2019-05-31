#include "project.hpp"

InstructionIncrementByte::InstructionIncrementByte(void) : AInstructions(INSTRUCTION_INCREMENT_BYTE) {}
InstructionIncrementByte::InstructionIncrementByte(InstructionIncrementByte const & src) { *this = src; }
InstructionIncrementByte::~InstructionIncrementByte(void) {}
InstructionIncrementByte&	InstructionIncrementByte::operator=(InstructionIncrementByte const &) { return *this; }

void	InstructionIncrementByte::execute(MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator&)
{
	++*mit;
}
