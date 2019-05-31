#ifndef INSTRUCTIONINCREMENTPOINTER_HPP
#define INSTRUCTIONINCREMENTPOINTER_HPP

#include "project.hpp"

class InstructionIncrementPointer : public AInstructions
{
public:
	InstructionIncrementPointer(void);
	InstructionIncrementPointer(InstructionIncrementPointer const &);
	~InstructionIncrementPointer(void);
	InstructionIncrementPointer	&operator=(InstructionIncrementPointer const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
