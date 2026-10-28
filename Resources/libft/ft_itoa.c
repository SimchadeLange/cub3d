/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:53:05 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/15 15:44:19 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_numbers(int number)
{
	int	count;
	int	negative_count;

	negative_count = 1;
	count = 0;
	if (number == 0)
		return (1);
	if (number == -2147483648)
		return (11);
	if (number < 0)
	{
		count++;
		number = number * -1;
	}
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	if (negative_count < 0)
		count = count + 1;
	return (count);
}

static	char	*ft_string_reverse(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[i] == 45)
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

static void	ft_conversion_itoa(char *nbrstr, int i, int n)
{
	if (n < 0)
	{
		nbrstr[i] = '-';
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		nbrstr[i++] = (n % 10) + 48;
		n = n / 10;
	}
	nbrstr[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	char	*nbrstr;

	nbrstr = malloc(sizeof(char) * (ft_count_numbers(n) + 1));
	i = 0;
	if (!nbrstr)
		return (NULL);
	if (n == 0)
	{
		nbrstr[0] = '0';
		nbrstr[1] = '\0';
		return (nbrstr);
	}
	if (n == -2147483648)
	{
		ft_strlcpy(nbrstr, "-2147483648", 12);
		return (nbrstr);
	}
	ft_conversion_itoa(nbrstr, i, n);
	ft_string_reverse (nbrstr);
	return (nbrstr);
}
