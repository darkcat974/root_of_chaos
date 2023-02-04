SRC = $(wildcard *.cpp)

CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -Iinclude

NAME = root_of_chaos

all:
	g++ -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -rf $(wildcard *~)

fclean:
	rm -rf $(NAME)

re: fclean all
