#ifndef INSTRUCTIONDECREMENTPOINTER_HPP
#define INSTRUCTIONDECREMENTPOINTER_HPP

#include "project.hpp"

class InstructionDecrementPointer : public AInstructions
{
public:
	InstructionDecrementPointer(void);
	InstructionDecrementPointer(InstructionDecrementPointer const &);
	~InstructionDecrementPointer(void);
	InstructionDecrementPointer	&operator=(InstructionDecrementPointer const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
