#include "span.hpp"

Span::Span(void) { }
Span::~Span(void) { }

Span::Span(unsigned int n): _maxSize(n) { }

Span::Span(Span const & src) { *this = src; }

Span &		Span::operator=(Span const & src)
{
	if (this != &src)
	{
		this->_v = src._v;
		this->_maxSize = src._maxSize;
	}
	return *this;
}

// fun stuff

void		Span::addNumber(int nbr)
{
	if(this->_v.size() == this->_maxSize)
		throw std::runtime_error("span is already full");
	this->_v.push_back(nbr);
}
