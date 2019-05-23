#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed(void);
	Fixed(Fixed const &src);

	Fixed &		operator=(Fixed const & src);
	bool		operator>(Fixed const & src) const;
	bool		operator<(Fixed const & src) const;
	bool		operator>=(Fixed const & src) const;
	bool		operator<=(Fixed const & src) const;
	bool		operator==(Fixed const & src) const;
	bool		operator!=(Fixed const & src) const;

	Fixed		operator+(Fixed const & src) const;
	Fixed		operator-(Fixed const & src) const;
	Fixed		operator*(Fixed const & src) const;
	Fixed		operator/(Fixed const & src) const;

	Fixed		operator++(int);
	Fixed		operator++(void);
	Fixed		operator--(int);
	Fixed		operator--(void);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;

	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed const  &	max(Fixed const & a, Fixed const & b);
	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed const  &	min(Fixed const & a, Fixed const & b);

private:
	int						_value;
	static const int 		_bits;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & src);

#endif
