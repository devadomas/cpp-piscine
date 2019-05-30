#include "project.hpp"

// Constructors & destructors
InstructionInput::InstructionInput( void ) : AInstructions(INSTRUCTION_INPUT) {}
InstructionInput::InstructionInput( InstructionInput const & src ) { *this = src; }
InstructionInput::~InstructionInput( void ) {}

// Operator override
InstructionInput&	InstructionInput::operator=( InstructionInput const & ) { return *this; }

// Member functions
void	InstructionInput::execute( MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator& )
{
	std::cin >> *mit;
}
