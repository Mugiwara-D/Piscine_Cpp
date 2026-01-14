SRC = Contact.cpp main.cpp PhoneBook.cpp 

NAME = Phonebook

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

INC = ./Include

FLAG = -Werror -Wall -Wextra -std=c++98 -MMD

CC = c++ 

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	
%.o : %.cpp
	$(CC) $(FLAG) -c $< -o $@

$(LIB) :
	@make -C $(LIB_D) 

clean :
	rm -f $(OBJ) $(DEP)

fclean:
	rm -f $(OBJ) $(DEP) $(NAME)

re : fclean all

.PHONY: all clean fclean re
