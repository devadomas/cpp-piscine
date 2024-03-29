#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value): _value(value << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value): _value(roundf(value * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void		Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float		Fixed::toFloat(void) const
{
	return float(this->_value) / (1 << Fixed::_bits);
}

int			Fixed::toInt(void) const
{
	return  this->_value >> Fixed::_bits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}
