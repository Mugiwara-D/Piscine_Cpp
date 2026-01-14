SRC = main_subject.cpp

NAME = Array

OBJ = $(SRC:.cpp=.o)

INC = ./Include

FLAG = -Werror -Wall -Wextra -std=c++98 

CC = c++ 

all : $(NAME) 

$(NAME) : $(OBJ) 
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	
%.o : %.cpp
	$(CC) $(FLAG) -c $< -o $@


clean :
	rm -f $(OBJ) $(DEP)

fclean:
	rm -f $(OBJ) $(DEP) $(NAME)

re : fclean all

.PHONY: all clean fclean re
