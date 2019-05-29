#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

template< typename T>
long		easyfind(T container, int number)
{
	typename T::iterator i;
	typename T::iterator iBegin = container.begin();
	typename T::iterator iEnd = container.end();
	if ((i = find(iBegin, iEnd, number)) != iEnd)
		return std::distance(iBegin, i);
	throw std::runtime_error("cannot find your number");
}

#endif
