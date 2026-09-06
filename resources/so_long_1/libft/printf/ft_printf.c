/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:42:49 by ede-roo           #+#    #+#             */
/*   Updated: 2025/09/29 21:07:31 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_p(char c)
{
	ft_buffer_filling(c);
	return (1);
}

int	ft_putstr_p(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_buffer_write_str("(null)"));
	while (str[i] != '\0')
	{
		ft_buffer_filling(str[i]);
		i++;
	}
	return (i);
}

int	ft_pointer_addr(void *ptr)
{
	uintptr_t	addr;
	int			count;

	if (!ptr)
		return (ft_buffer_write_str("(nil)"));
	addr = (uintptr_t)ptr;
	ft_buffer_write_str("0x");
	count = ft_puthexa_long(addr, "0123456789abcdef") + 2;
	return (count);
}

int	ft_type_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_p(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr_p(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_signed(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthexa_int(va_arg(args, int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_puthexa_int(va_arg(args, int), "0123456789ABCDEF"));
	else if (specifier == '%')
	{
		ft_buffer_filling('%');
		return (1);
	}
	else if (specifier == 'p')
		return (ft_pointer_addr(va_arg(args, void *)));
	else
		return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;	
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			count += ft_type_conversion(input[i], args);
		}
		else
			count += ft_putchar_p(input[i]);
		i++;
	}
	va_end(args);
	ft_buffer_write_flush();
	return (count);
}
