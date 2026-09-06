/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:09:17 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/22 16:53:50 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *str, int c)
{
	int				counter;
	unsigned char	d;

	if (!str)
		return (NULL);
	d = (unsigned char)c;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == d)
			return ((char *)str + counter);
		counter++;
	}
	if (d == '\0')
		return ((char *)str + counter);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		first_len;
	int		sec_len;
	char	*new_str;
	int		counter;

	first_len = str_search(s1, '\0');
	sec_len = str_search(s2, '\0');
	new_str = malloc((first_len + sec_len) + 1);
	if (!new_str)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		new_str[counter] = s1[counter];
		counter++;
	}
	counter = 0;
	while (s2[counter] != '\0')
	{
		new_str[counter + first_len] = s2[counter];
		counter++;
	}
	new_str[counter + first_len] = '\0';
	return (new_str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t			counter;
	char			*substr;
	unsigned int	check;

	if (!s)
		return (NULL);
	check = str_search(s, '\0');
	counter = 0;
	if (start >= check)
		return (duplicate_str(""));
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (s[counter + start] != '\0' && counter < len)
	{
		substr[counter] = s[counter + start];
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}

int	str_search(char *str, char c)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0' && str[counter] != c)
		counter++;
	//printf("strsearcj:%c\n", str[counter]);
	return (counter);
}

char	*duplicate_str(char *s1)
{
	int		counter;
	char	*str;
	int		length;

	if (!s1)
		return (NULL);
	counter = 0;
	length = str_search(s1, '\0');
	str = malloc((length * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[counter] != '\0')
	{
		str[counter] = s1[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
