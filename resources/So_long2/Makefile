# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 14:52:27 by side-lan          #+#    #+#              #
#    Updated: 2025/11/28 14:58:45 by side-lan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -ggdb -fsanitize=address

#Source files
SRC := so_long.c parse_map.c error_handling.c flood_fill.c read_and_render.c game_hook.c parser2.c

# libft
LIBFTDIR := ./Libft
LIBFT := $(LIBFTDIR)/libft.a

#MLX
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBMLX := ./MLX42
LIBS := build/libmlx42.a -ldl -lglfw -pthread -lm

# Object files
OBJ := $(SRC:.c=.o)

# Rules
all: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B build && make -C build -j4

$(NAME): $(OBJ) $(LIBFT) $(libmlx)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	rm -f $(OBJ)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
