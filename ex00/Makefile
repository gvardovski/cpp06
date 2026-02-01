CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = ScalarConverter
SRC =  main.cpp \
	src/ScalarConverter.cpp \
	src/Utils.cpp \
	src/Convert.cpp
OBJ = $(SRC:.cpp=.o)
%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re