SRC = main.cpp Fixed.cpp Point.cpp bsd.cpp 

NAME = Fixed

OBJ = $(SRC:.cpp=.o)

INC = ./Include

FLAG = -Werror -Wall -Wextra -std=c++98 -g3

CC = c++ 

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	
%.o : %.cpp
	$(CC) $(FLAG) -c $< -o $@

$(LIB) :
	@make -C $(LIB_D) 

clean :
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re : fclean all

.PHONY: all clean fclean re
