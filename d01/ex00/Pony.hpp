#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

#include <string>

class Pony
{
public:
	Pony(std::string name);
	~Pony();
	bool setAge(int age);
	int getAge() const;

private:
	std::string _name;
	std::string _kind;
	std::string _color;
	int _age;
};

#endif
