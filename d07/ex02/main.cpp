#include <iostream>
#include "Array.hpp"

int main (void)
{
	std::cout << "Build array" << std::endl;
	Array<int>		arr(1);
	try
	{
		std::cout << "I will try to add 0th element" << std::endl;
		arr[0] = 1;
		std::cout << "Successfull, no exception. item value : " << arr[0] << std::endl;
		std::cout << "Now I will try to add 1th element, should throw excpetion!" << std::endl;
		arr[1] = 2;
	}
	catch(std::exception & e)
	{
		std::cerr << "cougth error: " << e.what() << std::endl;
	}
	std::cout << "*** Will to do something with an empty array ***" << std::endl;
	try
	{
		std::cout << "*Creating an empty array" << std::endl;
		Array<int>		test;
		std::cout << "*Trying to reach non existing item" << std::endl;
		std::cout << test[10] << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << "cougth error: " << e.what() << std::endl;
	}
}
