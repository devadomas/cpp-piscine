#include "Squad.hpp"

Squad::Squad(void): _size(0) { }

Squad::~Squad(void)
{
	if (this->_size != 0)
	{
		for (int i = 0; i < this->_size; i++)
		{
			delete this->_arr[i];
			this->_arr[i] = NULL;
		}
	}
}

Squad::Squad(Squad const & src)
{
	this->_size = src.getCount();
	for (int i = 0; i < this->_size; i++)
		this->_arr[i] = src.getUnit(i)->clone();
	*this = src;
}

Squad &			Squad::operator=(Squad const & src)
{
	if (this != &src) // Clean before and add new ones!!!!!!
	{
		for (int i = 0; i < this->_size; i++)
		{
			delete this->_arr[i];
			this->_arr[i] = NULL;
		}
		for (int i = 0; i < this->_size; i++)
			this->_arr[i] = src.getUnit(i)->clone();
	}
	return *this;
}

int				Squad::getCount(void) const { return this->_size; }

ISpaceMarine *	Squad::getUnit(int n) const
{
	if (n < 0 || n >= this->_size || n >= NBR_MARINES)
		return NULL;
	return this->_arr[n];
}

int				Squad::push(ISpaceMarine * marine)
{
	if (marine == NULL || this->_size >= NBR_MARINES)
		return this->_size;
	for (int i = 0; i < this->_size; i++)
		if (this->_arr[i] == marine)
			return this->_size;
	// checked over
	this->_arr[this->_size] = marine;
	this->_size++;
	return this->_size;
}
