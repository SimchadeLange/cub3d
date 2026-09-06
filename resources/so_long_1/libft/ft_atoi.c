/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:12:23 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:04:45 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_beginof_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	sign = 1;
	nbr = 0;
	i = ft_beginof_str(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			nbr = nbr * 10 + (str[i] - 48);
		else
			return (nbr * sign);
		i++;
	}
	return (nbr * sign);
}
