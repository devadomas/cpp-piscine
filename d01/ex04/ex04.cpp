#include <string>
#include <iostream>

int			main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string	*	ptr = &str;
	std::string	&	ref = str;

	std::cout << "Using pointer: " << *ptr << std::endl;
	std::cout << "Using referance: " << ref << std::endl;
}
