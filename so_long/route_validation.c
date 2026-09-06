/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:03:42 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/05 02:17:24 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	route_trying(char **map_copy, t_sl *sl, size_t x, size_t y)
{
	if (!map_copy)
		return ;
	if (x >= sl->width || y >= sl->height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	map_copy[y][x] = 'F';
	route_trying(map_copy, sl, x + 1, y);
	route_trying(map_copy, sl, x - 1, y);
	route_trying(map_copy, sl, x, y + 1);
	route_trying(map_copy, sl, x, y - 1);
}

char	**make_map_copy(char **map, t_sl *sl)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc((sl->height + 1) * sizeof(char *));
	if (!map_copy)
		return (ft_printf("Error\nmap_copy mem alloaction failed\n"), NULL);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			ft_printf("Error\nFailed to copy map line\n");
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	route_validation(char **map, t_sl *sl)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = make_map_copy(map, sl);
	if (!map_copy)
		return (1);
	route_trying(map_copy, sl, sl->start_x, sl->start_y);
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map(map_copy);
				return (ft_printf("Error\nroute invalid C || E not reacheble\n")
					, 1);
			}
			j++;
		}
		i++;
	}
	return (free_map(map_copy), 0);
}
