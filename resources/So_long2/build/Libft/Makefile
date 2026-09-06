# Library name
NAME    := libft.a

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Archive tool
AR      := ar rcs

# Directories
PRINTFDIR := ./ft_printf
PRINTF    := $(PRINTFDIR)/libftprintf.a

# Source files
SRC := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
       ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
       ft_strlen.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
       ft_toupper.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# Object files
OBJ := $(SRC:.c=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	@cp $(PRINTF) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ Successfully built $(NAME)"

$(PRINTF):
	@make -C $(PRINTFDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(PRINTFDIR) clean
	@echo "🧹 Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean
	@echo "🗑️  Fully cleaned."

re: fclean all

.PHONY: all clean fclean re
