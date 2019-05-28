.PHONY: 		all clean fclean re

NAME 		= 	bureaucrat

SRCS		=	OfficeBlock.cpp Intern.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Form.cpp Bureaucrat.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CC 			=	clang++
CFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
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
