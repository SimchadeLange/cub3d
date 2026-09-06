/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:17:26 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 19:31:37 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	counter;
	int	negativ;

	num = 0;
	negativ = 1;
	counter = 0;
	while (str[counter] == ' ' || (str[counter] >= 9 && str[counter] <= 13))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			negativ = -1;
		counter++;
	}
	if (str[counter] < '0' || str[counter] > '9')
		return (0);
	while (str[counter] <= '9' && str[counter] >= '0')
		num = num * 10 + (str[counter++] - '0');
	return (num * negativ);
}
