#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP


class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const &src);
	Fixed &		operator=(Fixed const & rhs);
	int			getRawBits(void) const;
	void		setRawBits(int const raw);

private:
	int				_value;
	static const int _bits;
};

#endif
