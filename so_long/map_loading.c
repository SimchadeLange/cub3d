/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:48:15 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/04 23:19:38 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_line(int line_count, char *line, t_sl *sl, char *argv[])
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	sl->map_fd = open(argv[1], O_RDONLY);
	if (sl->map_fd < 0)
	{
		ft_printf("Error\nfailed to open map during copy'ing\n");
		exit(1);
	}
	while (i < line_count)
	{
		line = get_next_line(sl->map_fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len -1] == '\n')
			line[len -1] = '\0';
		sl->map[i] = line;
		i++;
	}
	sl->map[i] = NULL;
	close(sl->map_fd);
}

int	map_loading(char *argv[], t_sl *sl)
{
	int		line_count;
	char	*line;

	line_count = 0;
	sl->map_fd = open(argv[1], O_RDONLY);
	if (sl->map_fd < 0)
		return (ft_printf("Error\nmap failed to load\n"), 1);
	while (1)
	{
		line = get_next_line(sl->map_fd);
		if (!line)
			break ;
		line_count++;
		free(line);
	}
	close(sl->map_fd);
	if (line_count == 0)
		return (ft_printf("Error\nMap file is empty\n"), 1);
	sl->map = malloc((line_count + 1) * sizeof(char *));
	if (!sl->map)
		return (ft_printf("Error\nmap mem allocation failed\n"), 1);
	make_line(line_count, line, sl, argv);
	return (0);
}
