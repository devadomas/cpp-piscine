#include <iostream>
#include "mutantstack.hpp"

int			main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
    mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Other tests" << std::endl;
	MutantStack<int>	testStack;
	std::cout << "Pushing 1" << std::endl;
	testStack.push(1);
	std::cout << "Pushing 2" << std::endl;
	testStack.push(2);
	std::cout << "Pushing 3" << std::endl;
	testStack.push(3);
	std::cout << "Pushing 4" << std::endl;
	testStack.push(4);
	std::cout << "Top of stack: " << testStack.top() << std::endl;
	std::cout << "Stack size: " << testStack.size() << std::endl;
	return 0;
}
