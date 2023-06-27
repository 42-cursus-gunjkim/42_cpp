CXX=c++
CFLAGS=-std=c++98 -Wall -Wextra -Werror
NAME=ex00

SRCS= main.cpp \
	  Zombie.cpp \
	  newZombie.cpp \
	  randomChump.cpp \

OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

# %.o: %.cpp
# 	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
