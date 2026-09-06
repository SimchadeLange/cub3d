/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:59:04 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/05 00:13:59 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	map_limits(char **map, t_sl *sl)
{
	if (!map)
		return (ft_printf("Error\nmap did not load in validation\n"), 1);
	sl->width = ft_strlen(map[0]);
	while (map[sl->height])
	{
		if (sl->width != ft_strlen(map[sl->height]))
			return (ft_printf("Error\ninvalid map size detected\n"), 1);
		sl->height++;
	}
	if (sl->height <= MIN_HEIGHT || sl->width <= MIN_WIDTH)
		return (ft_printf("Error\nmap size too small\n"), 1);
	return (0);
}

int	map_tiles_checking(char **map, t_sl *sl, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
				return (ft_printf("Error\ninvalid character in map\n"), 1);
			if (map[i][j] == 'P')
			{
				sl->start_x = j;
				sl->start_y = i;
				sl->player++;
			}
			else if (map[i][j] == 'E')
				sl->exit++;
			else if (map[i][j] == 'C')
				sl->collectibles++;
			j++;
		}
		i++;
	}
	return (0);
}

int	map_validation(char **map, t_sl *sl)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (map_limits(map, sl) == 1)
		return (1);
	if (map_tiles_checking(map, sl, i, j))
		return (1);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][sl->width - 1] != '1')
			return (ft_printf("Error\ninvalid wall structure\n"), 1);
		i++;
	}
	if (sl->player != 1 || sl->exit != 1 || sl->collectibles < 1)
		return (ft_printf("Error\ninvalid amount of P||E||C \n"), 1);
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[sl->height - 1][j] != '1')
			return (ft_printf("Error\ninvalid wall structure\n"), 1);
		j++;
	}
	return (0);
}
