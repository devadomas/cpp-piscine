#include <iostream>
#include "Fixed.class.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &		Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator has been called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function has been called" << std::endl;
	return this->_value;
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function has been called" << std::endl;
	this->_value = raw;
}
