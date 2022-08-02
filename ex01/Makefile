NAME		=	a.out
CXX			=	clang++ $(CXXFLAGS) -std=c++98
42FLAGS		=	-Wall -Werror -Wextra
CXXFLAGS 	=	$(42FLAGS)
LDFLAGS		=	-fsanitize=address
SRCS		=	main.cpp Bureaucrat.cpp Form.cpp
OBJS		=	$(SRCS:.cpp=.o)

$(NAME):		$(OBJS)
				$(CXX) $(SRCS) -o $(NAME)

all:			$(NAME)

re:				fclean all

clean:			
				rm *.o

fclean:			clean
				rm -fr .vscode
				rm -f $(NAME)

.phony:			all re clean fclean
				
