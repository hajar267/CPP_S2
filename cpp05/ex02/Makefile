NAME = draw
HEADER=Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp 
files = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
obj := $(files:.cpp=.o)
Cpp = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME) : $(obj)
		$(Cpp) $(FLAGS) -o $@ $^

%.o:%.cpp $(HEADER)
		$(Cpp) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(obj)

fclean: clean
		rm -rf $(NAME)

re: fclean all