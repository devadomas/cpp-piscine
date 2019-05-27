.PHONY: 		all clean fclean re

NAME 		= 	ft_retro

CC 			=	clang++
CFLAGS		= 	-std=c++98 -pedantic-errors -g3 -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR 	=	./src/

SRC			=	ft_retro.cpp					\
				display/NCurses.cpp				\
				display/Frames.cpp				\
				entity/Boss.cpp					\
				entity/Bonus.cpp				\
				entity/Enemy.cpp				\
				entity/Entity.cpp				\
				entity/Projectile.cpp			\
				player/Player.cpp				\
				game/Game.cpp

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

OBJ_DIR 	=	./obj/
OBJ		 	=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR 	=	./includes/
INC 		=	ft_retro.hpp			\
				display/NCurses.hpp		\
				display/Frames.hpp		\
				entity/Boss.hpp			\
				entity/Bonus.hpp		\
				entity/Enemy.hpp		\
				entity/Entity.hpp		\
				entity/Projectile.hpp	\
				player/Player.hpp		\
				game/Game.hpp

INCS 		=	$(addprefix $(INC_DIR), $(INC))

all:	 		$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lncurses

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.cpp $(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/display
				@mkdir -p $(OBJ_DIR)/entity
				@mkdir -p $(OBJ_DIR)/game
				@mkdir -p $(OBJ_DIR)/player
				@mkdir -p $(OBJ_DIR)/util

clean:
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
