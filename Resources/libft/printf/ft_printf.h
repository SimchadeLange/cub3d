/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:11:09 by ede-roo           #+#    #+#             */
/*   Updated: 2025/09/29 21:10:47 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include "../libft.h"

typedef struct buffer_struct
{
	char	*data;
	int		size;
	int		capacity;
}	t_buffer_type;

int				ft_printf(const char *input, ...);
int				ft_putnbr_signed(int n);
int				ft_putnbr_unsigned(unsigned int n);
int				ft_puthexa_int(unsigned int n, const char *base);
int				ft_puthexa_long(unsigned long n, const char *base);
int				ft_putchar_p(char c);
int				ft_putstr_p(char *str);
int				ft_pointer_addr(void *ptr);
int				ft_type_conversion(char specifier, va_list args);

t_buffer_type	*ft_global_buffer(void);
void			ft_buffer_initialize(t_buffer_type *buffer);
void			ft_buffer_filling(char c);
void			ft_buffer_write_flush(void);
int				ft_buffer_write_str(char *str);

#endif
