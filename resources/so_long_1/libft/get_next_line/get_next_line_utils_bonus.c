/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:41:55 by ede-roo           #+#    #+#             */
/*   Updated: 2025/10/01 02:40:34 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*extract_line(char *leftover)
{
	int		i;
	int		j;
	char	*line;

	if (!leftover)
		return (NULL);
	i = 0;
	j = 0;
	while (leftover[i] != '\n' && leftover[i] != '\0')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = leftover[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_remove_extracted_line(char *leftover, char *line)
{
	char		*new_leftover;
	size_t		len_of_line;
	size_t		i;

	if (leftover == NULL || line == NULL)
		return (NULL);
	len_of_line = ft_strlen_gnl(line);
	if (len_of_line >= ft_strlen_gnl(leftover))
	{
		new_leftover = malloc(1);
		if (!new_leftover)
			return (NULL);
		new_leftover[0] = '\0';
		return (new_leftover);
	}
	new_leftover = (char *)malloc(ft_strlen_gnl(leftover) - len_of_line + 1);
	if (!new_leftover)
		return (NULL);
	i = -1;
	while (leftover[len_of_line + ++i] != '\0')
		new_leftover[i] = leftover[len_of_line + i];
	new_leftover[i] = '\0';
	return (new_leftover);
}
