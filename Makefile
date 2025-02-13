
NAME = exec
SRC = so_long.c map_parse.c map_check.c
CC = cc -Wall -Werror -Wextra
LIBS = -lmlx -lX11 -lXext -lft
LIBFT = libft
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all: $(NAME)

$(LIBFT):
	make -C ./libft && make -C ./libft clean

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(SRC) $(GNL) -I/usr/local/include -I./libft -L/usr/local/lib -L./libft $(LIBS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all