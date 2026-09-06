/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:45:36 by side-lan          #+#    #+#             */
/*   Updated: 2025/07/02 15:19:29 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*swap_str(char *str, int end);
static int	print_point(uintptr_t pointer);

int	print_hex(unsigned int num, int capital)
{
	int		counter;
	char	*str_hex;
	int		check;

	if (num == 0)
		return (write(1, "0", 1));
	counter = 0;
	str_hex = malloc(17);
	if (!str_hex)
		return (0);
	while (num > 0)
	{
		if (num % 16 < 10)
			str_hex[counter++] = (num % 16) + '0';
		else
			str_hex[counter++] = (num % 16) + (capital - 10);
		num /= 16;
	}
	str_hex[counter] = '\0';
	check = putstr(swap_str(str_hex, counter - 1));
	free(str_hex);
	return (check);
}

int	check_point(uintptr_t pointer)
{
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	return (print_point(pointer));
}

static int	print_point(uintptr_t pointer)
{
	int		counter;
	char	*str_hex;
	int		check;

	counter = 0;
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	str_hex = malloc(17);
	if (!str_hex)
		return (0);
	while (pointer > 0)
	{
		if (pointer % 16 < 10)
			str_hex[counter++] = (pointer % 16) + '0';
		else
			str_hex[counter++] = (pointer % 16) + ('a' - 10);
		pointer /= 16;
	}
	str_hex[counter] = '\0';
	check = putstr(swap_str(str_hex, counter - 1));
	free(str_hex);
	if (check == -1)
		return (-1);
	return (check + 2);
}

static char	*swap_str(char *str, int end)
{
	int		start;
	char	temp;

	temp = 0;
	start = 0;
	while (end > start)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
