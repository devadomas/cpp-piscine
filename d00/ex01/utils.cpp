#include <string>
#include "Phonebook.class.hpp"

std::string 	prepString(std::string str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

bool isNumber(const std::string& s)
{
    std::string::const_iterator it;

	it = s.begin();
    while (it != s.end() && std::isdigit(*it))
		++it;
    return (!s.empty() && it == s.end());
}

void	welcomeMsg(void)
{
	std::cout << "Welcome to Phonebook v1.0!" << std::endl;
	std::cout << "Here is a list of all possible commands:" << std::endl;
	std::cout << " * ADD - to add new contact to phonebook." << std::endl;
	std::cout << " * SEARCH - to search through phonebook." << std::endl;
	std::cout << " * EXIT - to exist and wipe all data." << std::endl;
}
