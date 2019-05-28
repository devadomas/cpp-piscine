#include <iostream>

/*
 Solution for Exercise
*/

template< typename T >
void		swap(T & s1, T & s2)
{
	T 		tmp = s1;

	s1 = s2;
	s2 = tmp;
}

template< typename T >
T			min(T const & s1, T const & s2)
{
	return (s1 > s2 ? s2 : s1);
}

template< typename T >
T			max(T const & s1, T const & s2)
{
	return (s1 > s2 ? s1 : s2);
}

/*
		Main and tests
*/


int		main(void)
{
	int		a = 5;
	int		b = 6;
	std::cout << "Before: " << std::endl
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After: " << std::endl
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl;
	std::cout << "Min max test" << std::endl;
	std::cout << "min(a, b) == " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) == " << ::max(a, b) << std::endl;

	std::cout << "It also works with strings!" << std::endl;
	std::string			s1 = "Test", s2 = "Not testing";
	std::cout << "Before: " << std::endl
				<< "s1 = " << s1 << std::endl
				<< "s2 = " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "After: " << std::endl
				<< "s1 = " << s1 << std::endl
				<< "s2 = " << s2 << std::endl;
}
