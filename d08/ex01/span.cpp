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

int			Span::longestSpan(void) const
{
	if (this->_v.size() < 2)
		throw std::runtime_error("there is not enough items to find span");

	int min = *(std::min_element(this->_v.begin(), this->_v.end()));
	int max = *(std::max_element(this->_v.begin(), this->_v.end()));
	return static_cast<int>(abs(max - min));
}

int			Span::shortestSpan(void) const
{
	if (this->_v.size() < 2)
		throw std::runtime_error("there is not enough items to find span");

	std::vector<int>		cpy(this->_v);
	int						arg1, arg2;

	std::sort(cpy.begin(), cpy.end());
	arg1 = cpy[0];
	arg2 = cpy[1];
	return static_cast<int>(abs(arg2 - arg1));
}
