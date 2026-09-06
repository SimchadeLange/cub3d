/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:17:51 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/16 19:12:19 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	long	num;

	num = n;
	counter = count_digits(n);
	if (num == 0)
		return (ft_strdup("0"));
	str = malloc(counter + 1);
	if (!str)
		return (NULL);
	str[counter] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[--counter] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
