NAME = span
HEADER= Span.hpp
files = main.cpp Span.cpp
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