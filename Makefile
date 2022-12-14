NAME		= pacman
SRCSDIR		= ./src
INCLUDES	= ./includes

SRCS		= *.cpp

CC			= g++
CFLAGS		=-Wall -Wextra -std=c++11 -I../#-Werror 


all: $(NAME)

$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "๐ช  Building ..."
	@$(CC) $(CFLAGS) -o $@ $^ -lncurses 
	@echo "โ Pacman is created!"

clean: 
	@rm -rf $(NAME)
	@echo "๐งจ  Destroyed"

re: clean all

.PHONY: all clean re 

# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp
