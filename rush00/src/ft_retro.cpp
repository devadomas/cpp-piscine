#include "ft_retro.hpp"

static void		keyStrokesHandler( Game & game, Player & player ) {
	int		key;

	if ((key = getch()) != ERR) {
		ungetch(key);

		int key = getch();
		if (key == 68)
			player.moveLeft();
		else if (key == 67)
			player.moveRight();
		else if (key == 65)
			player.moveUp();
		else if (key == 66)
			player.moveDown();
		else if (key == ' ')
			game.playerShot();
	}
}

int		main( int, char ** ) {

	NCurses		visual;

	// Ensure program does not run through lldb
	int width(visual.getWindowWidth());
	int height(visual.getWindowHeight());
	if (height == 0 || width == 0)
		return EXIT_FAILURE;

	// Setup game
	Player		player(width, height);
	Game		game(visual, player);
	Frames		frames(game, visual.menu(player));

	// Game has started
	while (player.getLives() > 0) {

		// Handle framing
		frames.handler();

		// Intercept key strokes
		keyStrokesHandler(game, player);

		// Update game
		game.update(frames.getGameDuration());
	}

	// End of game
	visual.printGameOver(player);

	return EXIT_SUCCESS;
}
