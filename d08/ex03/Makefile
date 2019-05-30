.PHONY: 		all clean fclean re

NAME 		= 	mindopen

CC 			=	clang++
CFLAGS		= 	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wconversion -I$(INC_DIR)

SRC_DIR 	=	./src/
SRC			=	main.cpp										\
				instructions/AInstructions.cpp					\
				instructions/InstructionDecrementByte.cpp		\
				instructions/InstructionDecrementPointer.cpp	\
				instructions/InstructionIncrementByte.cpp		\
				instructions/InstructionIncrementPointer.cpp	\
				instructions/InstructionInput.cpp				\
				instructions/InstructionJumpBackward.cpp		\
				instructions/InstructionJumpForward.cpp			\
				instructions/InstructionOutput.cpp				\
				mindopen/MindOpen.cpp
				

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

OBJ_DIR 	=	./obj/
OBJ		 	=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR 	=	./include/
INC 		=	AInstructions.hpp					\
				InstructionDecrementByte.hpp		\
				InstructionDecrementPointer.hpp		\
				InstructionIncrementByte.hpp		\
				InstructionIncrementPointer.hpp		\
				InstructionInput.hpp				\
				InstructionJumpBackward.hpp			\
				InstructionJumpForward.hpp			\
				InstructionOutput.hpp				\
				MindOpen.hpp						\
				project.hpp

INCS 		=	$(addprefix $(INC_DIR), $(INC))

all:	 		$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.cpp $(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/instructions
				@mkdir -p $(OBJ_DIR)/mindopen

clean:
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
