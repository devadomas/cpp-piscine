.PHONY: 		all clean fclean re

NAME 		= 	eval_expr

SRCS		=	Solver.class.cpp Vector.class.cpp Fixed.class.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CC 			=	clang++
CFLAGS		= 	-Wall -Wextra -Werror -std=c++98
OCFLAGS		=	-Wall -Wextra -Werror

all:	 		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OCFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
