/*#include "mutantstack.hpp"

MutantStack::MutantStack(void) : std::stack<T>::stack() { }


MutantStack::MutantStack(MutantStack const & src) : std::stack<T>::stack(src) { *this = src; }


MutantStack::~MutantStack(void) { }


MutantStack &			MutantStack::operator=(MutantStack const & src)
{
	std::stack<T>::operator=(src);
	return *this;
}


typename MutantStack::iterator				MutantStack::begin(void)
{
	return std::stack<T>::begin();
}


typename MutantStack::iterator				MutantStack::end(void)
{
	return std::stack<T>::end();
}
*/

/*
MutantStack is a template so it can be done in header file
*/
