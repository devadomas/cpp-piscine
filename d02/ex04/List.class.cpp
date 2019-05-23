#include "List.class.hpp"

List::List(void): _size(0), _arr(NULL) { }

List::~List(void)
{
	if (this->_size)
		delete [] this->_arr;
}

List::List(List const & src)
{
	*this = src;
}

List &			List::operator=(List const & src)
{
	if (this != &src)
	{
		this->_size = src._size;
		this->_arr = src._arr;
	}
	return *this;
}

int				List::getSize(void) const
{
	return this->_size;
}

std::string *		List::getArr(void) const
{
	return this->_arr;
}

void			List::pushBack(std::string const & value)
{
	std::string *		newArr = new std::string[this->_size + 1];

	if (this->_size != 0)
	{
		for (int i = 0; i < this->_size; i++)
			newArr[i] = this->_arr[i];
		delete[] this->_arr;
	}
	newArr[this->_size] = value;
	this->_size++;
	this->_arr = newArr;
}

std::string		List::popLast(void)
{
	if (!this->_size)
		return std::string();

	std::string		ret(this->_arr[this->_size - 1]);
	this->_size--;
	if (this->_size == 0)
	{
		delete[] this->_arr;
		this->_arr = NULL;
	}
	else
	{
		std::string *	newArr = new std::string[this->_size];
		for (int i = 0; i < this->_size; i++)
			newArr[i] = this->_arr[i];
		delete[] this->_arr;
		this->_arr = newArr;
	}
	return ret;
}

std::string			List::last(void) const
{
	if (this->_size == 0)
		return std::string();
	return this->_arr[this->_size - 1];
}
