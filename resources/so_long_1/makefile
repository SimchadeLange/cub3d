# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 00:16:18 by ede-roo           #+#    #+#              #
#    Updated: 2025/11/05 00:16:20 by ede-roo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft
RM = rm -f
OBJ_DIR = .o_files

SRC = map_loading.c map_validation.c route_validation.c main.c initialize_mlx.c player_movement.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) $(notdir $(LIBFT_A))

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

.PHONY: all clean fclean re
