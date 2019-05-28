#include <iostream>


template< typename T >
void		iter(T * arr, size_t length, void(&f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

/*
		Tests and main
*/

template< typename T >
void		print_arr(T & data)
{
	std::cout << "Received data: " << data << std::endl;
}

int			main(void)
{
	int		test[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	std::cout << "Testing: " << std::endl;
	iter(test, 10, print_arr);
}
