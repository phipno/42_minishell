NAME = minishell
CC = gcc
CFLAGS	= -Wall -Werror -Wextra
LIBNAME = ft
LIBDIR = ./lib/
SRCS	= src/main.c src/init.c src/swap_push.c src/rotate.c \
		src/reverse_rotate.c src/sort_big_stack.c src/sort_small_stack.c \
		src/utils.c src/find_and_search.c
OBJS	= $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	make -C ./lib

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) libft
	gcc $(OBJS) $(CFLAGS) -L $(LIBDIR) -l $(LIBNAME) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C ./lib clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft