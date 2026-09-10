CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g

NAME    := parser

LIBFT_DIR := ../libft
LIBFT     := $(LIBFT_DIR)/libft.a
INC     := -I$(LIBFT_DIR)

SRC     := 	srcs/parser_organiser.c \
			srcs/check_and_open_file.c \
			srcs/init_and_free_structs.c \
			srcs/array_funcs.c

OBJ     := $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re