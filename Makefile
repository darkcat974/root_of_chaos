##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = g++

SRC = 	$(shell find . -type f -name '*.cpp')

CFLAGS = -W -Werror -Wall -Wextra

OBJ	=	$(SRC:.cpp=.o)

LFLAGS = -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window

NAME	=	root_of_chaos

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(SRC) -o $(NAME) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
