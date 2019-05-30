#include "project.hpp"

// Constructors & destructors
InstructionDecrementByte::InstructionDecrementByte( void ) : AInstructions(INSTRUCTION_DECREMENT_BYTE) {}
InstructionDecrementByte::InstructionDecrementByte( InstructionDecrementByte const & src ) { *this = src; }
InstructionDecrementByte::~InstructionDecrementByte( void ) {}

// Operator override
InstructionDecrementByte&	InstructionDecrementByte::operator=( InstructionDecrementByte const & ) { return *this; }

// Member functions
void	InstructionDecrementByte::execute( MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator&)
{
	--*mit;
}
