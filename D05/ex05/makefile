NAME = Bureaucrat

SRC = main.cpp
SRC += Bureaucrat.cpp
SRC += Form.cpp
SRC += ShrubberyCreationForm.cpp
SRC += RobotomyRequestForm.cpp
SRC += PresidentialPardonForm.cpp
SRC += Intern.cpp
SRC += OfficeBlock.cpp
SRC += CentralBureaucracy.cpp

CLANG_FLAGS = -Wall -Wextra -Werror

CLANG = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(CLANG_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CLANG) $(CLANG_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re clean fclean