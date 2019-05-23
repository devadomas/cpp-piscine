#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void): _value(0) { }
Fixed::Fixed(int const value): _value(value << Fixed::_bits) { }
Fixed::Fixed(float const value): _value(roundf(value * (1 << Fixed::_bits))) { }
Fixed::~Fixed(void) { }

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed &		Fixed::operator=(Fixed const & src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int			Fixed::getRawBits(void) const
{
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

bool			Fixed::operator>(Fixed const & src) const
{
	return (this->toFloat() > src.toFloat());
}

bool			Fixed::operator<(Fixed const & src) const
{
	return (this->toFloat() < src.toFloat());
}

bool			Fixed::operator>=(Fixed const & src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool			Fixed::operator<=(Fixed const & src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool			Fixed::operator==(Fixed const & src) const
{
	return (this->toFloat() == src.toFloat());
}

bool			Fixed::operator!=(Fixed const & src) const
{
	return (this->toFloat() != src.toFloat());
}

Fixed			Fixed::operator+(Fixed const & src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed			Fixed::operator-(Fixed const & src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed			Fixed::operator*(Fixed const & src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed			Fixed::operator/(Fixed const & src) const
{
	return Fixed(this->toFloat() / src.toFloat());
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
