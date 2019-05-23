#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed(void);
	Fixed(Fixed const &src);
	Fixed &		operator=(Fixed const & src);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;

private:
	int					_value;
	static const int 	_bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
