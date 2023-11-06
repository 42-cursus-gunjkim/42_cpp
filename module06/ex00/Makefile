CXX=c++
CXXFLAGS=-std=c++98 -g
NAME=ex00

SRCS = main.cpp 			\
	   CharConverter.cpp	\
	   IntConverter.cpp		\
	   FloatConverter.cpp	\
	   DoubleConverter.cpp	\


OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re