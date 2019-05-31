#ifndef AINSTRUCTIONS_HPP
#define AINSTRUCTIONS_HPP

#include "project.hpp"

class AInstructions
{
public:

	typedef	std::vector<char>::iterator				memory_iterator;
	typedef std::vector<AInstructions*>::iterator	instructions_iterator;

	AInstructions(AInstructions const &);
	virtual ~AInstructions(void);
	AInstructions&	operator=(AInstructions const &);

	char			getType(void) const;
	virtual void	execute(memory_iterator&, memory_iterator&, memory_iterator&, instructions_iterator&) = 0;

protected:
	AInstructions(void);
	AInstructions(char);

private:
	char			_type;

};

#endif
