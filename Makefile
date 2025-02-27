NAME = so_long
CC = cc -Wall -Werror -Wextra

SRC = so_long.c map_parse.c map_check.c flood_fill.c utils.c map_rndr.c move_player.c

LIBFT = libft/libft.a
LIBFT_SRCS =./libft/ft_atoi.c		./libft/ft_isprint.c	./libft/ft_strnstr.c 	./libft/ft_strncmp.c	./libft/ft_striteri.c	\
			./libft/ft_bzero.c		./libft/ft_strdup.c		./libft/ft_strrchr.c 	./libft/ft_tolower.c	./libft/ft_split.c		\
			./libft/ft_memchr.c		./libft/ft_strlcat.c 	./libft/ft_toupper.c	./libft/ft_putchar_fd.c	./libft/ft_calloc.c		\
			./libft/ft_isalnum.c	./libft/ft_memcmp.c		./libft/ft_strlcpy.c 	./libft/ft_substr.c		./libft/ft_putstr_fd.c	\
			./libft/ft_isalpha.c	./libft/ft_memcpy.c		./libft/ft_strlen.c		./libft/ft_strjoin.c	./libft/ft_putendl_fd.c	\
			./libft/ft_isascii.c	./libft/ft_memmove.c	./libft/ft_strchr.c		./libft/ft_itoa.c		./libft/ft_putnbr_fd.c	\
			./libft/ft_isdigit.c	./libft/ft_memset.c		./libft/ft_strtrim.c 	./libft/ft_strmapi.c \

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.h

INCLUDES = -I/usr/local/include -I./libft -I./get_next_line

LIBS = -lmlx -lX11 -lXext -lft


all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(SRC) so_long.h
	$(CC) $(SRC) $(GNL) $(INCLUDES) -L/usr/local/lib -L./libft $(LIBS) -o $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	make -C libft

clean:
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re