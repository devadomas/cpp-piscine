#include <sstream>
#include "Brain.hpp"

Brain::Brain(void)
{
	this->_size = 0;
}

Brain::~Brain(void)
{

}

std::string		Brain::identify(void) const
{
	std::stringstream	addr;

	addr << this;
	return (addr.str());
}
