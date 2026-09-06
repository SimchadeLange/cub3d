/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:15:52 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:14:44 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_free_arr2(char **str_arr, int sep_str)
{
	int	i;	

	i = 0;
	while (i < sep_str)
	{
		free (str_arr[i]);
		i++;
	}
	free (str_arr);
}

static void	ft_arr_making2(int *sep_str, int *i, int *j)
{
	*sep_str = 0;
	*i = 0;
	*j = 0;
}

static char	**ft_arr_making(char const *s, char c, char **str_arr)
{
	int	i;
	int	j;
	int	sep_str;

	ft_arr_making2(&sep_str, &i, &j);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str_arr[sep_str] = ft_substr(s, j, (i - j));
			if (!str_arr[sep_str])
			{
				ft_free_arr2(str_arr, sep_str);
				return (NULL);
			}
			sep_str++;
		}
		else
			i++;
	}
	str_arr[sep_str] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = malloc (sizeof (char *) *(ft_str_count(s, c) + 1));
	if (!str_arr)
		return (NULL);
	if (!ft_arr_making (s, c, str_arr))
		return (NULL);
	return (str_arr);
}
