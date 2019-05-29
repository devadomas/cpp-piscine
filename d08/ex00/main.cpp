#include <vector>
#include <iostream>
#include "easyfind.hpp"

int			main(void)
{
	std::vector<int>		a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	std::cout << "First of 5 occurance at index: " << std::endl;
	try
	{
		std::cout << easyfind(a, 5) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Oops! Something went wrong! Reason: " << e.what() << std::endl;
	}
	std::cout << "-- Now let's find something invalid! --" << std::endl
				<< "First of -5 occurance at index: " << std::endl;;
	try
	{
			std::cout << easyfind(a, -5) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Oops! Something went wrong! Reason: " << e.what() << std::endl;
	}
}
