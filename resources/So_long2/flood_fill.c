/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:47:17 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/25 15:21:01 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_organizer(t_bigstruct *mapinfo)
{
	int		index;

	index = 0;
	flood_prepare(mapinfo);
	if (!mapinfo->copy)
		return (0);
	while (mapinfo->copy[index] != '\0')
	{
		if (mapinfo->copy[index] == 'E' || mapinfo->copy[index] == 'C')
			return (exit_program(mapinfo, "unreachable objects"), 0);
		index++;
	}
	return (1);
}

char	*flood_prepare(t_bigstruct	*mapinfo)
{
	int		width;
	int		x;
	int		y;
	int		height;

	y = 0;
	x = 0;
	height = find_indexes(mapinfo->map, &x, &y, &width);
	mapinfo->copy = ft_strdup(mapinfo->map);
	if (mapinfo->copy == NULL)
		return (exit_program(mapinfo, "malloc failed"), NULL);
	mapinfo->constants.width = width;
	mapinfo->constants.height = height;
	mapinfo->updates.p_x = x;
	mapinfo->updates.p_y = y;
	floodfill(x, y, mapinfo->constants, mapinfo);
	return (mapinfo->copy);
}

int	find_indexes(char *map, int *x, int *y, int *width)
{
	int	index;
	int	height;

	index = 0;
	height = get_height(map);
	*width = str_search(map, '\n') + 1;
	while (map[(*x) + (*width) * (*y)] != 'P')
	{
		if (map[*x + *width * *y] == '\n')
		{
			(*y)++;
			(*x) = 0;
		}
		else
			(*x)++;
	}
	return (height);
}

void	floodfill(int x, int y, t_constants sizes, t_bigstruct *mapinfo)
{
	int	index;

	index = x + (sizes.width * y);
	if (x < 0 || x == sizes.width || y < 0 || y == sizes.height)
		return ;
	if (mapinfo->copy[index] == 'E')
	{
		mapinfo->constants.e_x = x;
		mapinfo->constants.e_y = y;
	}
	if (flood_check(mapinfo->copy[index]) == 0)
	{
		mapinfo->copy[index] = 'x';
		floodfill(x, y + 1, sizes, mapinfo);
		floodfill(x, y - 1, sizes, mapinfo);
		floodfill(x + 1, y, sizes, mapinfo);
		floodfill(x - 1, y, sizes, mapinfo);
	}
}

int	flood_check(char c)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (0);
	return (1);
}
