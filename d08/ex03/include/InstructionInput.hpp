#ifndef INSTRUCTIONINPUT_HPP
#define INSTRUCTIONINPUT_HPP

#include "project.hpp"

class InstructionInput : public AInstructions
{
public:
	InstructionInput(void);
	InstructionInput(InstructionInput const &);
	~InstructionInput(void);
	InstructionInput	&operator=(InstructionInput const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
