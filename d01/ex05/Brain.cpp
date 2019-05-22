#include <sstream>
#include <ctime>
#include "Brain.hpp"

Brain::Brain(void)
{
	// for rand() to work
	std::srand(std::time(nullptr));
	this->_size = 0;
	this->_brainCells = rand() % 10;
}

Brain::~Brain(void) { }

std::string		Brain::identify(void) const
{
	std::stringstream	addr;

	addr << this;
	return (addr.str());
}
