SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

NAME = Job

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
