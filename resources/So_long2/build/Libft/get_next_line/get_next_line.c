/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:33:17 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/06 16:15:53 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(char **str, int fd, char *buffer);
char	*cut_newline(char *str, char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0)
		return (NULL);
	if (buffer[0] == '\0')
		str = duplicate_str("");
	else
		str = duplicate_str(buffer);
	if (!str)
		return (NULL);
	str = read_buffer(&str, fd, buffer);
	if (!str)
		return (NULL);
	str = cut_newline(str, buffer);
	return (str);
}

char	*read_buffer(char **str, int fd, char *buffer)
{
	char	*temp;
	int		read_return;

	while (!(ft_strchr_gnl(buffer, '\n')))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if ((read_return == 0 && buffer[0] == '\0') || read_return == -1)
		{
			free(*str);
			buffer[0] = '\0';
			return (NULL);
		}
		if (read_return == 0 && buffer[0] != '\0')
		{
			buffer[0] = '\0';
			return (*str);
		}
		buffer[read_return] = '\0';
		temp = *str;
		*str = ft_strjoin_gnl(temp, buffer);
		free(temp);
		if (!*str)
			return (NULL);
	}
	return (*str);
}

char	*cut_newline(char *str, char *buffer)
{
	int		counter;
	int		index;
	char	*temp;

	index = 0;
	if (ft_strchr_gnl(str, '\n'))
	{
		counter = str_search(str, '\n');
		temp = str;
		str = ft_substr_gnl(str, 0, counter + 1);
		free(temp);
	}
	if (ft_strchr_gnl(buffer, '\n'))
	{
		counter = str_search(buffer, '\n');
		while (buffer[counter + 1] != '\0')
			buffer[index++] = buffer[counter++ + 1];
		buffer[index] = '\0';
	}
	temp = NULL;
	return (str);
}
