CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g

NAME    := raycast

LIBFT_DIR := ../libft
LIBFT     := $(LIBFT_DIR)/libft.a

MLX_DIR := MLX42
MLX     := $(MLX_DIR)/build/libmlx42.a

INC     := -I$(MLX_DIR)/include -I$(LIBFT_DIR)

UNAME   := $(shell uname)
ifeq ($(UNAME),Darwin)
	MLX_FLAGS := $(MLX) -lglfw -L"$(HOME)/.brew/opt/glfw/lib" \
	             -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_FLAGS := $(MLX) -ldl -lglfw -pthread -lm
endif

SRC     := main.c draw.c hooks.c init_player.c raycast.c \
           stub_parser.c window_management.c

OBJ     := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

%.o: %.c header_raycast.h ../header.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
