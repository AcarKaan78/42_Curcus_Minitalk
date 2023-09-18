NAME = client

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra client.c -o client
	gcc -Wall -Werror -Wextra server.c -o server

clean:
	rm -rf client server

fclean: clean

re: fclean all