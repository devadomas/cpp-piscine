#ifndef INSTRUCTIONDECREMENTBYTE_HPP
#define INSTRUCTIONDECREMENTBYTE_HPP

#include "project.hpp"

class InstructionDecrementByte : public AInstructions
{
public:
	InstructionDecrementByte(void);
	InstructionDecrementByte(InstructionDecrementByte const &);
	~InstructionDecrementByte(void);
	InstructionDecrementByte	&operator=(InstructionDecrementByte const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
