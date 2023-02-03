##
## EPITECH PROJECT, 2023
## SFML
## File description:
## Makefile
##

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

# IFLAGS	=	-I./include

# LFLAGS	=	-L./lib/my/ -lmy

CFLAGS 	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# NFLAGS	=	-W -Wall -Werror -Wextra

NAME	=	root

all:	$(NAME)

$(NAME):	$(OBJ)
			g++ -c main.cpp
			g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME) $(OBJ)

re: fclean all