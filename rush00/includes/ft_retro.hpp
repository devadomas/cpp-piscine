#ifndef FT_RETRO_HPP
#define FT_RETRO_HPP

// game
#define GAME_START_LIVES 					5
#define GAME_MAX_LIVES						5
#define GAME_MAX_BONUSES					10
#define GAME_MAX_ENEMIES					30
#define GAME_MAX_PROJECTILES				100

// bonuses
#define PLAYER_BOOST_DURATION				5
#define PLAYER_SHIELD_DURATION				5

#define BONUS_LIVE							"live"
#define BONUS_BOOST							"boost"
#define BONUS_SHIELD						"shield"

// heights and widths
#define ENEMY_WIDTH							11
#define ENEMY_HEIGHT						5
#define BOSS_WIDTH							18
#define BOSS_HEIGHT							5
#define PROJECTILE_WIDTH					1
#define PROJECTILE_HEIGHT					1
#define	DEFAULT_PLAYER_WIDTH				5
#define DEFAULT_PLAYER_HEIGHT				5
#define DEFAULT_PLAYER_DISPLAY_WIDTH		24
#define DEFAULT_PLAYER_DISPLAY_HEIGHT		10

// scores
#define SCORE_ENEMY_SHOT					200
#define SCORE_ENEMY_DOWN					1000
#define SCORE_BOSS_SHOT						500
#define SCORE_BOSS_DOWN						30000
#define PLAYER_DEFAULT_SCORE_MULT			2

// player moves
#define	PLAYER_MOVE_HORIZONTAL				2
#define PLAYER_MOVE_VERTICAL				1

// projectile specific
#define PROJECTILE_DEFAULT_DAMAGES			1

// enemy specific
#define ENEMY_DEFAULT_Y						0
#define ENEMY_DEFAULT_LIVES					2
#define ENEMY_DEFAULT_DAMAGES				1

// boss specific
#define BOSS_DEFAULT_MOVE					2
#define BOSS_DEFAULT_Y						5
#define BOSS_DEFAULT_LIVES					50
#define BOSS_DEFAULT_DAMAGES				1

// frames indexes
#define F_ENEMY								0
#define F_ENEMY_SHOT						1
#define F_BOSS								2
#define F_BOSS_SHOT							3
#define F_BOSS_MOVE							4
#define F_BONUS								5

// frames
#define F_EASY_ENEMY						3000
#define F_MEDIUM_ENEMY						2000
#define F_HARD_ENEMY						1000

#define F_EASY_ENEMY_SHOT					3000
#define F_MEDIUM_ENEMY_SHOT					2000
#define F_HARD_ENEMY_SHOT					1000

#define F_EASY_BOSS							120000
#define F_MEDIUM_BOSS						60000
#define F_HARD_BOSS							30000

#define F_EASY_BOSS_SHOT					6000
#define F_MEDIUM_BOSS_SHOT					3000
#define F_HARD_BOSS_SHOT					2000

#define F_EASY_BOSS_MOVE					2000
#define F_MEDIUM_BOSS_MOVE					500
#define F_HARD_BOSS_MOVE					250

#define F_EASY_BONUS						5000
#define F_MEDIUM_BONUS						15000
#define F_HARD_BONUS						30000

#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <locale.h>

#include "display/NCurses.hpp"
#include "display/Frames.hpp"
#include "entity/Entity.hpp"
#include "entity/Boss.hpp"
#include "entity/Bonus.hpp"
#include "entity/Enemy.hpp"
#include "entity/Projectile.hpp"
#include "game/Game.hpp"
#include "player/Player.hpp"

#endif
