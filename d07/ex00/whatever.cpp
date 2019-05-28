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
	int		a = 2;
	int		b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
