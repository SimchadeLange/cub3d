/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:12:23 by ede-roo           #+#    #+#             */
/*   Updated: 2025/09/29 11:34:17 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line/get_next_line_bonus.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/* Character functions */
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

/* String Functions*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *small, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);

/* Memory functions*/
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

/* Conversion Functions*/
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* FD Output Functions*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

/*get_next_line functions*/
char	*extract_line(char *leftover);
char	*ft_strjoin_and_free(char *leftover, char *buffer);
char	*ft_remove_extracted_line(char *leftover, char *line);
char	*read_and_store(char *buffer, char *leftover,
			ssize_t bytes_read, int fd);
char	*get_next_line(int fd);
char	*process_leftover(char *leftover, char *line);

/*ft_printf */
int		ft_printf(const char *input, ...);
int		ft_putnbr_signed(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthexa_int(unsigned int n, const char *base);
int		ft_puthexa_long(unsigned long n, const char *base);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_pointer_addr(void *ptr);
int		ft_type_conversion(char specifier, va_list args);
void	ft_buffer_filling(char c);
void	ft_buffer_write_flush(void);
int		ft_buffer_write_str(char *str);

#endif
