##
## EPITECH PROJECT, 2023
## SFML
## File description:
## Makefile
##

SRC	=	$(wildcard *.cpp)

OBJ	=	$(SRC:.cpp=.o)

IFLAGS	=	-I./include

CFLAGS 	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	root

all:	$(NAME)

$(NAME):	$(OBJ)
			g++ -c main.cpp
			g++ -o $(NAME) $(OBJ) $(CFLAGS) $(IFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME) $(OBJ)

re: fclean all