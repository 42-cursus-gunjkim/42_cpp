CXX=c++
CFLAGS=-std=c++98 -Wall -Wextra -Werror
NAME=ex01

SRCS= main.cpp \
	  Animal.cpp \
	  Cat.cpp \
	  Dog.cpp \
	  WrongAnimal.cpp \
	  WrongCat.cpp \
	  Brain.cpp \

OBJS= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
