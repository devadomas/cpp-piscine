#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
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

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
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

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool			Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool			Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool			Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool			Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool			Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool			Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed			Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed			Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed			Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed			Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed		Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return tmp;
}

Fixed		Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed		Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return tmp;
}

Fixed		Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed &			Fixed::max(Fixed & a, Fixed & b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed &			Fixed::min(Fixed & a, Fixed & b)
{
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}
