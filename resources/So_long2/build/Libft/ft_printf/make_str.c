/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:59:38 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/23 21:05:11 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr(char *str)
{
	int	counter;
	int	check;

	if (!str)
		return (write(1, "(null)", 6));
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	check = write(1, str, counter);
	return (check);
}

int	count_digits(long n)
{
	int	counter;

	counter = 1;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n > 9)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

int	make_str(long n)
{
	int		counter;
	char	*str;
	int		temp;

	temp = 0;
	counter = count_digits(n);
	str = malloc(counter + 1);
	if (!str)
		return (0);
	str[counter] = '\0';
	counter--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		temp = 1;
	}
	while (counter >= 0 + temp)
	{
		str[counter] = (n % 10) + '0';
		n /= 10;
		counter--;
	}
	temp = putstr(str);
	return (free(str), temp);
}

int	make_unstr(unsigned long n)
{
	int		counter;
	char	*str;
	int		temp;

	temp = 0;
	counter = count_digits(n);
	str = malloc(counter + 1);
	if (!str)
		return (0);
	str[counter] = '\0';
	counter--;
	while (counter >= 0 + temp)
	{
		str[counter] = (n % 10) + '0';
		n /= 10;
		counter--;
	}
	temp = putstr(str);
	return (free(str), temp);
}
