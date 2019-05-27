#include "ft_retro.hpp"

// Constructor & destructor
NCurses::NCurses( void ) : _pairIndex(70), _foreground(COLOR_WHITE), _background(COLOR_BLACK) {
	setlocale(LC_ALL, "");
	initscr();
	start_color();
	// Init all possible pairs
	for ( short i = 0; i < 8 ; i++ ) {	
		for ( short j = 0; i < 8 ; i++ ) {

			std::stringstream	foreground;
			std::stringstream	background;
			foreground << j;
			background << i;
			std::string 		pairIndexStrA = foreground.str() + background.str();
			std::string 		pairIndexStrB = background.str() + foreground.str();

			int pairIndexA;
			int pairIndexB;
			std::istringstream(pairIndexStrA) >> pairIndexA;
			std::istringstream(pairIndexStrB) >> pairIndexB;
			init_pair(pairIndexA, i, j);
			if (i != j)
				init_pair(pairIndexB, j, i);
		}
	}
	noecho();
	curs_set(0);
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();

	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) >= 0) {
		this->_winWidth = size.ws_col;
		this->_winHeight = size.ws_row;
	} else {
		this->_winWidth = 0;
		this->_winHeight = 0;
	}
}
NCurses::~NCurses( void ) { endwin(); }


// Getters
int		NCurses::getWindowWidth( void ) const { return this->_winWidth; }
int		NCurses::getWindowHeight( void ) const { return this->_winHeight; }



// Color handlers
void	NCurses::setPairIndex( void ) {
	std::stringstream foreground;
	std::stringstream background;

	foreground << this->_foreground;
	background << this->_background;

	std::string pairIndexStr = background.str() + foreground.str();
	
	int pairIndex;
	std::istringstream(pairIndexStr) >> pairIndex;
	this->_pairIndex = pairIndex;
}
void	NCurses::selectColor( void ) const { attron(COLOR_PAIR(this->_pairIndex)); }
void	NCurses::unselectColor( void ) const { attroff(COLOR_PAIR(this->_pairIndex)); }
void	NCurses::setForeground( short color ) {
	this->_foreground = color;
	this->unselectColor();
	this->setPairIndex();
	this->selectColor();
}
void	NCurses::setBackground( short color ) {
	this->_background = color;
	this->unselectColor();
	this->setPairIndex();
	this->selectColor();
}
void	NCurses::setColors( short background, short foreground ) {
	this->_background = background;
	this->_foreground = foreground;
	this->unselectColor();
	this->setPairIndex();
	this->selectColor();
}


// Display
void	NCurses::clearScreen( void ) {
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_BLACK);
	for (int i = 0 ; i < this->_winHeight ; i++)
		mvprintw(i, 0, "%*s", this->_winWidth, "");
}

void	NCurses::print( int y, int x, std::string content) const { mvprintw(y, x, content.c_str()); }


int	NCurses::menu( Player const & player ) {
	int		key = 0;
	int		index = 1; // 0 = easy | 1 = medium | 2 = hard
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_GREEN);
	mvprintw(this->_winHeight / 2 - 7, this->_winWidth / 2 - 32,"                          _                     _               ");
	mvprintw(this->_winHeight / 2 - 6, this->_winWidth / 2 - 32,"                         (_)                   | |              ");
	mvprintw(this->_winHeight / 2 - 5, this->_winWidth / 2 - 32," ___ _ __   __ _  ___ ___ _ _ ____   ____ _  __| | ___ _ __ ___ ");
	mvprintw(this->_winHeight / 2 - 4, this->_winWidth / 2 - 32,"/ __| '_ \\ / _` |/ __/ _ \\ | '_ \\ \\ / / _` |/ _` |/ _ \\ '__/ __|");
	mvprintw(this->_winHeight / 2 - 3, this->_winWidth / 2 - 32, "\\__ \\ |_) | (_| | (_|  __/ | | | \\ V / (_| | (_| |  __/ |  \\__ \\");
	mvprintw(this->_winHeight / 2 - 2, this->_winWidth / 2 - 32,"|___/ .__/ \\__,_|\\___\\___|_|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/");
	mvprintw(this->_winHeight / 2 - 1, this->_winWidth / 2 - 32,"    | |                                                         ");
	mvprintw(this->_winHeight / 2 - 0, this->_winWidth / 2 - 32,"    |_|                                                         ");
	while ( key != 10 ) {
		if ((key = getch()) != ERR) {
			ungetch(key);

			key = getch();
			if (key == 65)
				index = (index - 1 < 0) ? 2 : index - 1;
			else if (key == 66)
				index = (index + 1 > 2) ? 0 : index + 1;
		}
		(index == 0) ? this->setColors(COLOR_WHITE, COLOR_BLACK) : this->setColors(COLOR_BLACK, COLOR_WHITE);
		mvprintw(this->_winHeight / 2 + 6, this->_winWidth / 2 - 7,  "       E A S Y       ");
		(index == 1) ? this->setColors(COLOR_WHITE, COLOR_BLACK) : this->setColors(COLOR_BLACK, COLOR_WHITE);
		mvprintw(this->_winHeight / 2 + 8, this->_winWidth / 2 - 7,  "     M E D | U M     ");
		(index == 2) ? this->setColors(COLOR_WHITE, COLOR_BLACK) : this->setColors(COLOR_BLACK, COLOR_WHITE);
		mvprintw(this->_winHeight / 2 + 10, this->_winWidth / 2 - 7, "       H A R D       ");
	}
	this->setColors(COLOR_BLACK, COLOR_WHITE);
	mvprintw(this->_winHeight / 2 + 12, this->_winWidth / 2 - 7, "( press Enter )");
	this->clearScreen();
	this->print(player);
	return index;
}

void	NCurses::printGameOver( Player const & player ) {
	this->clearScreen();
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_RED);
	mvprintw(this->_winHeight / 2 - 7, this->_winWidth / 2 - 32, "  ________                        ________                     ");
	mvprintw(this->_winHeight / 2 - 6, this->_winWidth / 2 - 32, " /  _____/_____    _____   ____   \\_____  \\___  __ ___________ ");
	mvprintw(this->_winHeight / 2 - 5, this->_winWidth / 2 - 32, "/   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\");
	mvprintw(this->_winHeight / 2 - 4, this->_winWidth / 2 - 32, "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/");
	mvprintw(this->_winHeight / 2 - 3, this->_winWidth / 2 - 32, " \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|   ");
	mvprintw(this->_winHeight / 2 - 2, this->_winWidth / 2 - 32, "        \\/     \\/      \\/     \\/          \\/          \\/       ");
	this->setForeground(COLOR_YELLOW);
	mvprintw(this->_winHeight / 2 + 2, this->_winWidth / 2 - 11, "Final score: %010d", player.getScore());
	this->setForeground(COLOR_WHITE);
	mvprintw(this->_winHeight / 2 + 6, this->_winWidth / 2 - 7, "( press Enter )");
	while (getch() != 10) {}
}

void	NCurses::print( Player const & player ) {

	// Print player itself
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_GREEN);

	// SHIELD
	if (player.hasShield() && player.hasBoost()) {
		mvprintw(player.getY() + 0, player.getX(), "  .    . ▄  ▄  ▄    .   ");
		mvprintw(player.getY() + 1, player.getX(), "    . ▀  .    .   ▀     ");
		mvprintw(player.getY() + 2, player.getX(), " .  ▀  .    ▄    .  ▀   ");
		mvprintw(player.getY() + 3, player.getX(), "  ▀ .    ▄▄███▄▄      ▀ ");
		mvprintw(player.getY() + 4, player.getX(), "  ▀   ▄████▀▀▀████▄   ▀ ");
		mvprintw(player.getY() + 5, player.getX(), "  █   █████▄▄▄█████   █ ");
		mvprintw(player.getY() + 6, player.getX(), "  ▄ .  ▀███▀▀▀███▀    ▄ ");
		mvprintw(player.getY() + 7, player.getX(), "    ▄  .    .   .   ▄   ");
		mvprintw(player.getY() + 8, player.getX(), "  .    ▄  .      ▄     .");
		mvprintw(player.getY() + 9, player.getX(), "   .      ▀   ▀ .   .   ");

	} else if (player.hasShield()) {
		mvprintw(player.getY() + 0, player.getX(), "         ▄  ▄  ▄        ");
		mvprintw(player.getY() + 1, player.getX(), "      ▀           ▀     ");
		mvprintw(player.getY() + 2, player.getX(), "    ▀       ▄       ▀   ");
		mvprintw(player.getY() + 3, player.getX(), "  ▀      ▄▄███▄▄      ▀ ");
		mvprintw(player.getY() + 4, player.getX(), "  ▀   ▄████▀▀▀████▄   ▀ ");
		mvprintw(player.getY() + 5, player.getX(), "  █   █████▄▄▄█████   █ ");
		mvprintw(player.getY() + 6, player.getX(), "  ▄    ▀███▀▀▀███▀    ▄ ");
		mvprintw(player.getY() + 7, player.getX(), "    ▄               ▄   ");
		mvprintw(player.getY() + 8, player.getX(), "       ▄         ▄      ");
		mvprintw(player.getY() + 9, player.getX(), "          ▀   ▀         ");

	} else if (player.hasBoost()) {
		mvprintw(player.getY() + 0, player.getX(), "       .     .      .   ");
		mvprintw(player.getY() + 1, player.getX(), "   .             .      ");
		mvprintw(player.getY() + 2, player.getX(), "      .     ▄        .  ");
		mvprintw(player.getY() + 3, player.getX(), "   .     ▄▄███▄▄    .   ");
		mvprintw(player.getY() + 4, player.getX(), ".     ▄████▀▀▀████▄   . ");
		mvprintw(player.getY() + 5, player.getX(), "      █████▄▄▄█████   . ");
		mvprintw(player.getY() + 6, player.getX(), "  .    ▀███▀▀▀███▀  .   ");
		mvprintw(player.getY() + 7, player.getX(), "       .              . ");
		mvprintw(player.getY() + 8, player.getX(), "    .     .   .    .    ");
		mvprintw(player.getY() + 9, player.getX(), "       .     .          ");

	} else {
		mvprintw(player.getY() + 0, player.getX(), "*                      *");
		mvprintw(player.getY() + 1, player.getX(), "                        ");
		mvprintw(player.getY() + 2, player.getX(), "            ▄           ");
		mvprintw(player.getY() + 3, player.getX(), "         ▄▄███▄▄        ");
		mvprintw(player.getY() + 4, player.getX(), "      ▄████▀▀▀████▄     ");
		mvprintw(player.getY() + 5, player.getX(), "      █████▄▄▄█████     ");
		mvprintw(player.getY() + 6, player.getX(), "       ▀███▀▀▀███▀      ");
		mvprintw(player.getY() + 7, player.getX(), "                        ");
		mvprintw(player.getY() + 8, player.getX(), "                        ");
		mvprintw(player.getY() + 9, player.getX(), "*                      *");
	}
}

void	NCurses::print( Enemy * enemy ) {
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_RED);
	if (enemy->getLives() == 1)
		this->setForeground(COLOR_YELLOW);

	int	type = enemy->getType();
	int x = enemy->getX();
	int y = enemy->getY();
	if (type == 0) {
		mvprintw(y + 0, x, "  ▀▄   ▄▀  ");
		mvprintw(y + 1, x, " ▄█▀███▀█▄ ");
		mvprintw(y + 2, x, "█▀███████▀█");
		mvprintw(y + 3, x, "█ █▀▀▀▀▀█ █");
		mvprintw(y + 4, x, "   ▀▀ ▀▀   ");
	} else if (type == 1) {
		mvprintw(y + 0, x, "▄ ▀▄   ▄▀ ▄");
		mvprintw(y + 1, x, "█▄███████▄█");
		mvprintw(y + 2, x, "███▄███▄███");
		mvprintw(y + 3, x, "▀█████████▀");
		mvprintw(y + 4, x, " ▄▀     ▀▄ ");
	} else if (type == 2) {
		mvprintw(y + 0, x, " ▄▄█████▄▄ ");
		mvprintw(y + 1, x, "███████████");
		mvprintw(y + 2, x, "██▄▄███▄▄██");
		mvprintw(y + 3, x, " ▄▀▄▀▀▀▄▀▄ ");
		mvprintw(y + 4, x, "▀         ▀");
	} else if (type == 3) {
		mvprintw(y + 0, x, "   ▄███▄   ");
		mvprintw(y + 1, x, " ▄███████▄ ");
		mvprintw(y + 2, x, "███▄███▄███");
		mvprintw(y + 3, x, "  ▄▀▄▄▄▀▄  ");
		mvprintw(y + 4, x, " ▀ ▀   ▀ ▀ ");
	}
}

void	NCurses::print( Boss * boss ) {
	this->setBackground(COLOR_BLACK);
	if (boss->getLives() < 25)
		this->setForeground(COLOR_YELLOW);
	else
		this->setForeground(COLOR_MAGENTA);
	int x = boss->getX();
	int y = boss->getY();
	mvprintw(y + 0, x, "                  ");
	mvprintw(y + 1, x, "     ▄▄████▄▄     ");
	mvprintw(y + 2, x, "   ▄██████████▄   ");
	mvprintw(y + 3, x, " ▄██▄██▄██▄██▄██▄ ");
	mvprintw(y + 4, x, "   ▀█▀  ▀▀  ▀█▀   ");
	mvprintw(y + 5, x, "                  ");
}

void	NCurses::print( Projectile * projectile ) {
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_YELLOW);
	mvprintw(projectile->getY(), projectile->getX(), "█");
}

void	NCurses::print( Bonus* bonus ) {
	std::string		type = bonus->getType();
	if (type == BONUS_SHIELD)
		mvprintw(bonus->getY(), bonus->getX(), "💢");
		// mvprintw(bonus->getY(), bonus->getX(), "🔲");
	else if (type == BONUS_BOOST)
		mvprintw(bonus->getY(), bonus->getX(), "🚀");
	else if (type == BONUS_LIVE)
		mvprintw(bonus->getY(), bonus->getX(), "💖");
}

void	NCurses::print( Player const & player, int duration ) {
	// Print lives
	int	nbLives = player.getLives();
	this->setForeground(COLOR_WHITE);
	for (int index = GAME_MAX_LIVES ; index >= 1; index-- ) {
		if (index == nbLives)
			this->setForeground(COLOR_RED);
		mvprintw(1, this->_winWidth - index * 3 - 4, "❤");
	}
	// Print score
	this->setForeground(COLOR_YELLOW);
	mvprintw(2, this->_winWidth - 20, "%015d", player.getScore());

	// Print shield
	int	shield = player.hasShield();
	if (shield == 0) {
		this->setForeground(COLOR_RED);
		mvprintw(4, this->_winWidth - 20, "No shield");
	} else {
		this->setForeground(COLOR_GREEN);
		mvprintw(4, this->_winWidth - 20, "Shield ends in %02d", shield - duration );
	}

	// Print boost
	int	boost = player.hasBoost();
	if (boost == 0) {
		this->setForeground(COLOR_RED);
		mvprintw(5, this->_winWidth - 20, "No XP boost");
	} else {
		this->setForeground(COLOR_GREEN);
		mvprintw(5, this->_winWidth - 20, "XP Boost ends in %02d", boost - duration );
	}

	// Print duration
	this->setBackground(COLOR_BLACK);
	this->setForeground(COLOR_WHITE);
	int	min(duration / 60);
	int sec(duration % 60);
	mvprintw(this->_winHeight - 1, this->_winWidth - 6, "%02d:%02d", min, sec);
}
