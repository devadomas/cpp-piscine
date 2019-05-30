#include "project.hpp"

// Constructors & destructors
InstructionOutput::InstructionOutput( void ) : AInstructions(INSTRUCTION_OUTPUT) {}
InstructionOutput::InstructionOutput( InstructionOutput const & src ) { *this = src; }
InstructionOutput::~InstructionOutput( void ) {}

// Operator override
InstructionOutput&	InstructionOutput::operator=( InstructionOutput const & ) { return *this; }

// Member functions
void	InstructionOutput::execute( MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator &)
{
	if (isprint(*mit) || (*mit >= 9 && *mit <= 13))
		std::cout << *mit;
}
