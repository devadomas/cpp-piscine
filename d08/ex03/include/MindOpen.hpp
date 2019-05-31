#ifndef MINDOPEN_HPP
#define MINDOPEN_HPP

#include "project.hpp"

class MindOpen
{
public:
	typedef	std::vector<char>						memory;
	typedef	std::vector<char>::iterator				memory_iterator;

	typedef	std::vector<AInstructions*>				instructions;
	typedef std::vector<AInstructions*>::iterator	instructions_iterator;

	MindOpen(void);
	MindOpen(MindOpen const &);
	~MindOpen(void);

	void				parse(std::string const);
	void				execute(void);

private:
	MindOpen&	operator=(MindOpen const &);

	memory				_memory;
	instructions		_instructions;

};

#endif
