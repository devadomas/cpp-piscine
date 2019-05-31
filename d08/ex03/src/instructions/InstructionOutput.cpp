#include "project.hpp"

InstructionOutput::InstructionOutput(void) : AInstructions(INSTRUCTION_OUTPUT) {}
InstructionOutput::InstructionOutput(InstructionOutput const & src) { *this = src; }
InstructionOutput::~InstructionOutput(void) {}
InstructionOutput&	InstructionOutput::operator=(InstructionOutput const &) { return *this; }

void	InstructionOutput::execute(MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator &)
{
	if (isprint(*mit) || (*mit >= 9 && *mit <= 13))
		std::cout << *mit;
}
