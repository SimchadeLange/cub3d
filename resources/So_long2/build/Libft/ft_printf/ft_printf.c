/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:47:18 by side-lan          #+#    #+#             */
/*   Updated: 2025/07/02 14:18:54 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_format(int total, int *counter, const char *fmt);
static int	is_percentage(int total, int *counter, const char *fmt);
static int	is_variable(int total, int *counter, const char *fmt, va_list args);
static int	is_valid_signifier(char c);

int	ft_printf(const char *fmt, ...)
{
	int		counter;
	int		total;
	va_list	args;

	counter = 0;
	total = 0;
	va_start(args, fmt);
	while (fmt[counter] != '\0')
	{
		if (fmt[counter] == '%' && !(is_valid_signifier(fmt[counter + 1])))
			total = is_percentage(total, &counter, fmt);
		if (fmt[counter] == '%' && is_valid_signifier(fmt[counter + 1]))
		{
			counter++;
			total = is_variable(total, &counter, fmt, args);
			counter++;
		}
		if (fmt[counter] != '\0' && fmt[counter] != '%')
			total = is_format(total, &counter, fmt);
		if (total == -1)
			return (-1);
	}
	va_end(args);
	return (total);
}

static int	is_valid_signifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

static int	is_format(int total, int *counter, const char *fmt)
{
	int	check;
	int	start;

	if (fmt[*counter] == '%' && !(is_valid_signifier(fmt[*counter + 1])))
		return (-1);
	start = *(counter);
	check = 0;
	while (fmt[*(counter)] != '%' && fmt[*(counter)] != '\0')
		(*counter)++;
	check = write(1, fmt + start, *(counter) - start);
	if (check == -1)
		return (-1);
	return (check + total);
}

static int	is_percentage(int total, int *counter, const char *fmt)
{
	int	check;

	if (fmt[*counter] == '%' && fmt[*counter + 1] == '%')
	{
		*counter += 2;
		check = write(1, "%", 1);
	}
	else
		return (-1);
	if (check == -1)
		return (check);
	return (check + total);
}

static int	is_variable(int total, int *counter, const char *fmt, va_list args)
{
	int	check;
	int	temp;

	if (fmt[*(counter)] == 'c')
	{
		temp = va_arg(args, int);
		check = write(1, &temp, 1);
	}
	if (fmt[*(counter)] == 's')
		check = putstr(va_arg(args, char *));
	if (fmt[*(counter)] == 'p')
		check = check_point(va_arg(args, uintptr_t));
	if (fmt[*(counter)] == 'd')
		check = make_str(va_arg(args, int));
	if (fmt[*(counter)] == 'i')
		check = make_str(va_arg(args, int));
	if (fmt[*(counter)] == 'u')
		check = make_unstr(va_arg(args, unsigned int));
	if (fmt[*(counter)] == 'x')
		check = print_hex(va_arg(args, int), 'a');
	if (fmt[*(counter)] == 'X')
		check = print_hex(va_arg(args, int), 'A');
	if (check == -1)
		return (check);
	return (check + total);
}
