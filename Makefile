# CC		:= cc
# CFLAGS	:= -I src/ # -Wall -Werror -Wextra  
# VPATH	:= src/
# OBJ_DIR	:= obj/
# PRINTF	:= lib/ft_printf/libftprintf.a

# NAME	:= minishell

# SRC		:=	main.c 

# OBJ		:=	$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))


# all: $(NAME)

# # $(PRINTF):
# # 	make --directory=./lib/printf

# $(OBJ_DIR): 
# 	mkdir obj

# $(OBJ_DIR)%.o: %.c 
# 	$(CC) $(CFLAGS) $< -c -o $@


# libft:
# 	make -C ./lib

# $(NAME): $(OBJ_DIR) $(OBJ) libft
# 	$(CC) $(OBJ) -o $(NAME) $(PRINTF) $(LDFLAGS)

# # clean:
# # 	make clean --directory=./lib/ft_printf	
# # 	rm -f $(OBJ)

# # fclean: clean
# # 	make fclean --directory=./lib/ft_printf
# # 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


NAME	:= minishell
CC		:= cc
CFLAGS	:= -I src/ -I lib/ -Wall -Werror -Wextra
LDFLAGS	:= -L ~/.brew/opt/readline/lib/
VPATH	:= src/
OBJ_DIR	:= obj/

SRC		:=	main.c \
			big_L.c \
			foo.c

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