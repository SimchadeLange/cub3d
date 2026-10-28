NAME		:= cub3D

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEPFLAGS	:= -MMD -MP

# ---------------------------------------------------------------- libraries
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MLX_DIR		:= _Raycast/MLX42
MLX			:= $(MLX_DIR)/build/libmlx42.a

UNAME		:= $(shell uname)
ifeq ($(UNAME),Darwin)
	MLX_FLAGS := $(MLX) -lglfw -L"$(HOME)/.brew/opt/glfw/lib" \
				 -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_FLAGS := $(MLX) -ldl -lglfw -pthread -lm
endif

INC			:= -I. -I_Raycast -I_Parser/includes \
			   -I$(LIBFT_DIR) -I$(MLX_DIR)/include

# ------------------------------------------------------------------ sources
# Root main.c replaces _Raycast/main.c; the real parser replaces stub_parser.c.
SRC_MAIN	:= main.c

SRC_RAY		:= _Raycast/draw.c \
			   _Raycast/hooks.c \
			   _Raycast/init_player.c \
			   _Raycast/raycast.c \
			   _Raycast/window_management.c \
			   _Raycast/load_config.c

SRC_PARSER	:= _Parser/srcs/array_funcs.c \
			   _Parser/srcs/error_handling/error_funcs.c \
			   _Parser/srcs/get_elements/check_file.c \
			   _Parser/srcs/get_elements/parse_elements.c \
			   _Parser/srcs/init_and_free_structs.c \
			   _Parser/srcs/map_handling.c \
			   _Parser/srcs/parser_organiser.c \
			   _Parser/srcs/test_funcs.c

SRC			:= $(SRC_MAIN) $(SRC_RAY) $(SRC_PARSER)

OBJ_DIR		:= obj
OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP			:= $(OBJ:.o=.d)

# ------------------------------------------------------------------ rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	cmake --build $(MLX_DIR)/build -j4

bonus: all

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all bonus clean fclean re