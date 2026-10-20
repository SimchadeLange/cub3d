CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g

NAME    := raycast

MLX_DIR := MLX42
MLX     := $(MLX_DIR)/build/libmlx42.a
INC     := -I$(MLX_DIR)/include

UNAME   := $(shell uname)
ifeq ($(UNAME), Darwin)
	MLX_FLAGS := $(MLX) -lglfw -L"$(HOME)/.brew/opt/glfw/lib" \
	             -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_FLAGS := $(MLX) -ldl -lglfw -pthread -lm
endif

SRC     := 	main.c \
			draw.c \
			hooks.c \
			init_player.c \
			raycast.c \
			stub_parser.c \
			window_management.c

OBJ     := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re