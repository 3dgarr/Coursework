NAME		= pacman
SRCSDIR		= ./src
INCLUDES	= ./includes

SRCS		= *.cpp

CC			= g++
CFLAGS		= -Wall -Wextra -std=c++11 -I../#-Werror 


all: $(NAME)

$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "🌪  Building ..."
	@$(CC) $(CFLAGS) -o $@ $^ -lncurses 
	@echo "✅ Pacman is created!"

clean:

fclean: clean
	@rm -rf $(NAME)
	@echo "🧨  Destroyed"

re: fclean all

.PHONY: all clean fclean re 

# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp
