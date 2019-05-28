#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template< typename T >
class Array {
public:
	Array(void): _arr(NULL), _size(0) {};
	Array(unsigned int n): _arr(new T[n]), _size(n) {};
	Array(Array const &src)
	{
		this->_size = src.size();
		this->_arr = new T[this->_size];
		for (unsigned int i = 0; i < src._size; i++)
			this->_arr[i] = src._arr[i];
	}
	Array &			operator=(Array const &src) const
	{
		this->_size = src.size();
		this->_arr = new T[this->_size];
		for (unsigned int i = 0; i < src._size; i++)
			this->_arr[i] = src._arr[i];
	}
	~Array(void) { delete[] this->_arr; }

	T &			operator[](unsigned int i) const
	{
		if (i >= this->_size)
			throw std::out_of_range("array index bad - out of bounds");
		return this->_arr[i];
	}

	unsigned int	size(void) const { return this->_size; }

private:
	T * 			_arr;
	unsigned int 	_size;

};

#endif
