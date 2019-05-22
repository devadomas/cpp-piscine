#include <iostream>
#include <string>

void memoryLeak()
{
	std::string*        panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere; // deletion of memory leak
}

/*
//	main() for correction
int main()
{
	memoryLeak();
}
*/
