.PHONY: 		all clean fclean re

NAME 		= 	ex04

CC 			=	clang++
CFLAGS		= 	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wconversion -I$(INC_DIR)

SRC_DIR 	=	./src/
SRC			=	main.cpp Solver.class.cpp


SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

OBJ_DIR 	=	./obj/
OBJ		 	=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR 	=	./include/
INC 		=	Solver.class.hpp

INCS 		=	$(addprefix $(INC_DIR), $(INC))

all:	 		$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.cpp $(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
