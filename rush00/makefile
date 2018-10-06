NAME = ft_retro

SRC = main.cpp
SRC += Logger.cpp
SRC += Input.cpp

CLANG_FLAGS = -Wall -Wextra -Werror

CLANG = clang++

NCURSES = -lncurses

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(NCURSES) $(CLANG_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CLANG) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re clean fclean
