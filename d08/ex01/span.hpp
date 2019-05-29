#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int);
	~Span(void);
	Span(Span const &);
	Span &					operator=(Span const &);

	//
	void					addNumber(int nbr);
	int						longestSpan(void) const;
	int						shortestSpan(void) const;

private:
	std::vector<int>		_v;
	unsigned int			_maxSize;

	Span(void); //unused
};

#endif
