#include "project.hpp"

// Constructors & destructors
InstructionIncrementPointer::InstructionIncrementPointer( void ) : AInstructions(INSTRUCTION_INCREMENT_POINTER) {}
InstructionIncrementPointer::InstructionIncrementPointer( InstructionIncrementPointer const & src ) { *this = src; }
InstructionIncrementPointer::~InstructionIncrementPointer( void ) {}

// Operator override
InstructionIncrementPointer&	InstructionIncrementPointer::operator=( InstructionIncrementPointer const & ) { return *this; }

// Member functions
void	InstructionIncrementPointer::execute( MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator& end, MindOpen::instructions_iterator& )
{
	if (mit + 1 != end)
		mit++;
}
