/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:41:51 by ede-roo           #+#    #+#             */
/*   Updated: 2025/10/01 02:40:52 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_store(char *buffer, char *leftover,
	ssize_t bytes_read, int fd)
{
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!leftover)
	{
		leftover = malloc(1);
		if (!leftover)
			return (NULL);
		leftover[0] = '\0';
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_and_free(leftover, buffer);
		if (!temp)
			return (free(leftover), NULL);
		leftover = temp;
		if (ft_strchr(leftover, '\n'))
			return (leftover);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!leftover || !leftover[0])))
		return (free(leftover), NULL);
	return (leftover);
}

char	*ft_strjoin_and_free(char *leftover, char *buffer)
{
	char	*s3;
	int		i;
	int		j;

	i = ft_strlen_gnl(leftover);
	j = ft_strlen_gnl(buffer);
	s3 = (char *) malloc((sizeof (char)) * (i + j + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (leftover[i] != '\0')
	{
		s3[i] = leftover[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		s3[i + j] = buffer[j];
		j++;
	}
	s3[i + j] = '\0';
	free(leftover);
	return (s3);
}

char	*process_leftover(char *leftover, char *line)
{
	char	*new_leftover;

	new_leftover = ft_remove_extracted_line(leftover, line);
	free(leftover);
	if (!new_leftover)
	{
		new_leftover = malloc(1);
		if (!new_leftover)
			return (NULL);
		new_leftover[0] = '\0';
	}
	if (!*new_leftover)
	{
		free(new_leftover);
		return (NULL);
	}
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftovers[OPEN_MAX];
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	leftovers[fd] = read_and_store(buffer, leftovers[fd], bytes_read, fd);
	free(buffer);
	if (!leftovers[fd])
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	line = extract_line(leftovers[fd]);
	if (!line)
		return (free(leftovers[fd]), leftovers[fd] = NULL, NULL);
	leftovers[fd] = process_leftover(leftovers[fd], line);
	return (line);
}
