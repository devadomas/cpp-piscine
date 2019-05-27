#ifndef BONUS_HPP
# define BONUS_HPP

# include "ft_retro.hpp"

class Bonus : public Entity {

public:

	// Constructors & destructor
	Bonus( int, int, std::string );
	virtual ~Bonus( void );

	// Getters and setters
	void			setType(std::string const & type);
	std::string		getType(void) const;

private:

	// Constructors & destructor
	Bonus( void );
	Bonus( Bonus const & );

	// Operator override
	Bonus &	operator=(Bonus const &);

	// Member attributes
	std::string		_type;

};

#endif
