#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {

public:

	// Creates a type to use iterators on class
	typedef typename std::stack<T>::container_type::iterator iterator;

	// Constructors and destructor
	MutantStack( void ) : std::stack<T>() {}
	MutantStack( MutantStack const & src ) : std::stack<T>::stack(src) { *this = src; }
	virtual ~MutantStack( void ) {}

	// Operators override
	MutantStack& operator=(MutantStack const & src) {
		std::stack<T>::operator=(src);
		return *this;
	}

	// Accessors
	iterator	begin( void ) { return std::stack<T>::c.begin(); }
	iterator	end( void ) { return std::stack<T>::c.end(); }
};

#endif
