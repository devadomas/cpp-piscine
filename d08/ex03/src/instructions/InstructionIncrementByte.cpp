#include "project.hpp"

// Constructors & destructors
InstructionIncrementByte::InstructionIncrementByte( void ) : AInstructions(INSTRUCTION_INCREMENT_BYTE) {}
InstructionIncrementByte::InstructionIncrementByte( InstructionIncrementByte const & src ) { *this = src; }
InstructionIncrementByte::~InstructionIncrementByte( void ) {}

// Operator override
InstructionIncrementByte&	InstructionIncrementByte::operator=( InstructionIncrementByte const & ) { return *this; }

// Member functions
void	InstructionIncrementByte::execute( MindOpen::memory_iterator& mit, MindOpen::memory_iterator&, MindOpen::memory_iterator&, MindOpen::instructions_iterator&)
{
	++*mit;
}
