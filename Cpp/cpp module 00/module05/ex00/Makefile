# 42 C++ Module 05 - ex00: Bureaucrat
NAME        := bureaucrat
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
SRCS        := src/main.cpp src/Bureaucrat.cpp
OBJS        := $(SRCS:.cpp=.o)
INCDIR      := include
INCLUDES    := -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
