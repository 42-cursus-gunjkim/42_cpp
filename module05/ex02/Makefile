CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror
NAME=ex02

SRCS = main.cpp						\
	   Bureaucrat.cpp				\
	   AForm.cpp					\
	   ShrubberyCreationForm.cpp	\
	   RobotomyRequestForm.cpp		\
	   PresidentialPardonForm.cpp	\


OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *_shrubbery
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re