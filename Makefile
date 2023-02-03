SRC = $(wildcard *.cpp)

OBJ = $(SRC:.c=.o)

CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -Iinclude

NAME = root_of_chaos

all:
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
