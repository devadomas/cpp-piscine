#ifndef INSTRUCTIONINCREMENTBYTE_HPP
#define INSTRUCTIONINCREMENTBYTE_HPP

#include "project.hpp"

class InstructionIncrementByte : public AInstructions
{
public:
	InstructionIncrementByte(void);
	InstructionIncrementByte(InstructionIncrementByte const &);
	~InstructionIncrementByte(void);
	InstructionIncrementByte	&operator=(InstructionIncrementByte const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
