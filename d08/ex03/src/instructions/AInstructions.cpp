#include "project.hpp"


AInstructions::AInstructions(void) {}
AInstructions::AInstructions(char type) : _type(type) {}
AInstructions::AInstructions(AInstructions const & src) { *this = src; }
AInstructions::~AInstructions(void) {}
AInstructions&	AInstructions::operator=(AInstructions const & src)
{
	if (this != &src)
		this->_type = src.getType();
	return *this;
}


char	AInstructions::getType(void) const { return this->_type; }
