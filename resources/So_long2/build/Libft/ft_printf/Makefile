# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 19:53:03 by side-lan          #+#    #+#              #
#    Updated: 2025/06/23 20:11:06 by side-lan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

AR      := ar rcs

NAME    := libftprintf.a

SRC := ft_printf.c make_hex.c make_str.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
