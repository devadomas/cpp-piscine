#ifndef INSTRUCTIONOUTPUT_HPP
#define INSTRUCTIONOUTPUT_HPP

#include "project.hpp"

class InstructionOutput : public AInstructions
{
public:
	InstructionOutput(void);
	InstructionOutput(InstructionOutput const &);
	~InstructionOutput(void);
	InstructionOutput	&operator=(InstructionOutput const &);

	virtual void 	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&);
};

#endif
