NAME	:= minishell
CC		:= cc
CFLAGS	:= -I src/ -I lib/ #-Wall -Werror -Wextra
LDFLAGS	:= -lreadline -L ~/.brew/opt/readline/lib/
VPATH	:= src/
OBJ_DIR	:= obj/

SRC		:=	main.c \
			parser.c\
			tokenizer.c \

OBJ		:= $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

LIBFT	:= lib/libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) $(LDFLAGS)

$(OBJ_DIR): 
	mkdir obj

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) $< -c -o $@

$(LIBFT):
	make -C ./lib

clean:
	make -C ./lib clean
	rm -f $(OBJ)

fclean: clean
	make -C ./lib fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft