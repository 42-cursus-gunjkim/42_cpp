CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror
NAME=ex01

SRCS=main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re