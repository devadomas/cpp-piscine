#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "ft_retro.hpp"

/*
	Available colors:
      COLOR_BLACK
      COLOR_RED
      COLOR_GREEN
      COLOR_YELLOW
      COLOR_BLUE
      COLOR_MAGENTA
      COLOR_CYAN
      COLOR_WHITE
*/

class Player;
class Enemy;
class Boss;
class Projectile;
class Bonus;

class NCurses {

public:

	// Constructors & destructor
	NCurses( void );
	~NCurses( void );

	// Getters and setters
	int		getWindowHeight( void ) const ;
	int		getWindowWidth( void ) const ;
	void	setForeground( short );
	void	setBackground( short );
	void	setColors( short, short );

	// Member functions
	void	print( int, int, std::string ) const;
	void	print( Player const & );
	void	print( Enemy * );
	void	print( Boss * );
	void	print( Projectile * );
	void	print( Bonus * );
	void	print( Player const &, int );
	int		menu( Player const & );
	void	printGameOver( Player const & );
	void	clearScreen( void );

private:

	// Member attributes
	int		_winWidth;
	int		_winHeight;
	short	_pairIndex;
	short	_foreground;
	short	_background;


	// Member functions
	void	setPairIndex( void );
	void	selectColor( void ) const;
	void	unselectColor( void ) const;

	// Constructors & destructor
	NCurses( NCurses const & );

	// Operator override
	NCurses &	operator=( NCurses const & );

};

#endif
