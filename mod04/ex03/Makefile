SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp

NAME = materia

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

INC = ./Include

FLAG = -Werror -Wall -Wextra -std=c++98 -MMD -g3

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
