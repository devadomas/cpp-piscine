#include "Vector.class.hpp"

Vector::Vector(void) : _count(0), _array(NULL) { }

Vector::~Vector(void)
{
	if (!this->empty())
		delete [] this->_array;
}

Vector::Vector(Vector const & src)
{
	*this = src;
}

Vector&			Vector::operator=(Vector const & src)
{
	if (this != &src)
	{
		this->_count = src.size();
		this->_array = src.getArray();
	}
	return *this;
}

std::string			Vector::operator[](int index) const
{
	if (this->_count == 0 || index < 0 || index >= this->_count)
		return std::string();
	return this->_array[index];
}

// FUN stuff

int					Vector::size(void) const { return this->_count; }
std::string*		Vector::getArray(void) const { return this->_array; }
bool				Vector::empty(void) const { return this->_count == 0; }

void				Vector::push(std::string const & value)
{
	std::string*	array = new std::string[this->_count + 1];
	if (this->_count)
	{
		for (int i = 0 ; i < this->_count; i++)
			array[i] = this->_array[i];
		delete [] this->_array;
	}
	array[this->_count] = value;
	this->_count++;
	this->_array = array;
}

void				Vector::reverse(void)
{
	int		end(this->_count - 1);

	for (int i = 0 ; i < this->_count / 2; i++)
	{
		std::string		tmp(this->_array[i]);
		this->_array[i] = this->_array[end];
		this->_array[end] = tmp;
		end--;
	}
}

std::string			Vector::pop(void)
{
	if (this->_count == 0)
		return std::string();

	std::string		value(this->_array[this->_count - 1]);

	this->_count--;
	if (this->_count == 0)
	{
		delete [] this->_array;
		this->_array = NULL;
	}
	else
	{
		std::string*	array = new std::string[this->_count];
		for (int i = 0 ; i < this->_count ; i++)
			array[i] = this->_array[i];
		delete [] this->_array;
		this->_array = array;
	}
	return value;
}

void				Vector::removeAt(int idx)
{
	if (this->_count == 0 || idx < 0 || idx >= this->_count)
		return ;

	this->_count--;
	if (this->_count == 0)
	{
		delete [] this->_array;
		this->_array = NULL;
	}
	else
	{
		std::string*	array = new std::string[this->_count];

		for (int i = 0; i < idx; i++)
			array[i] = this->_array[i];
		for (int i = idx; i < this->_count; i++)
			array[i] = this->_array[i + 1];
		delete [] this->_array;
		this->_array = array;
	}
}

void				Vector::insertAt(int idx, std::string value)
{
	std::string*	array = new std::string[this->_count + 1];

	if (this->_count)
	{
		for (int i = 0 ; i < idx; i++)
			array[i] = this->_array[i];
		array[idx] = value;
		for (int i = idx + 1; i <= this->_count; i++)
			array[i] = this->_array[i - 1];
		delete [] this->_array;
	}
	else
		array[this->_count] = value;
	this->_count++;
	this->_array = array;
}

std::string 		Vector::back(void) const
{
	if (this->_count == 0)
		return std::string();
	return this->_array[this->_count - 1];
}

std::ostream &		operator<<(std::ostream & o, Vector const & src)
{
	if (src.empty())
		o << "Vector is empty.";
	else
		for (int i = 0 ; i < src.size() ; i++)
			if (i == src.size() - 1)
				o << "Vector[" << i << "] : " << src[i] << std::endl;
			else
				o << "Vector[" << i << "] : " << src[i] << std::endl;
	return o;
}
