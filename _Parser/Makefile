CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g

NAME      := parser

LIBFT_DIR := ../libft
LIBFT     := $(LIBFT_DIR)/libft.a
INC       := -I$(LIBFT_DIR)

SRC       := srcs/parser_organiser.c \
             srcs/get_elements/check_file.c \
             srcs/init_and_free_structs.c \
             srcs/array_funcs.c \
             srcs/get_elements/parse_elements.c \
             srcs/error_handling/error_funcs.c \
             srcs/map_handling.c \
             srcs/test_funcs.c \
			 ../main.c
OBJ_DIR   := obj
OBJ       := $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re