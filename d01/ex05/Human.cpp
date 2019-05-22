#include "Human.hpp"

Human::Human(void): _brainRef(*(new Brain))
{
	this->_brain = &(this->_brainRef);
}

Human::~Human(void)
{
	delete this->_brain;
}

std::string		Human::identify(void) const
{
	return (this->_brain->identify());
}

Brain&			Human::getBrain(void) const
{
	return (this->_brainRef);
}
