/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:39:05 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/28 14:58:08 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parse_organizer(char *argv[], t_bigstruct *mapinfo)
{
	int		counter;
	int		p_check;
	int		e_check;

	counter = 0;
	p_check = 0;
	e_check = 0;
	mapinfo->map = read_file(argv[1], mapinfo);
	if (!mapinfo->map)
		return (NULL);
	if (!check_valid_symbols(mapinfo->map))
		return (exit_program(mapinfo, "invalid characters"), NULL);
	if (!check_object_count(mapinfo, p_check, e_check))
		return (NULL);
	if (!check_shape(mapinfo->map))
		return (exit_program(mapinfo, "invalid shape"), NULL);
	if (!check_walls(mapinfo->map, counter))
		return (exit_program(mapinfo, "map not bound by walls"), NULL);
	if (!flood_organizer(mapinfo))
		return (NULL);
	return (mapinfo->map);
}

int	check_shape(char *str)
{
	int	new_line;
	int	old_width;
	int	index;

	index = 0;
	new_line = 0;
	old_width = str_search(str, '\n');
	while (old_width == str_search(str + new_line, '\n'))
	{
		new_line = old_width + new_line + 1;
		if (str[new_line - 1] == '\0' && str[new_line - 2] != '\n')
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_walls(char *str, int y)
{
	int	x;
	int	index;
	int	width;
	int	height;

	index = 0;
	width = str_search(str, '\n');
	height = get_height(str);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			index = x + (width + 1) * y;
			if (str[index] == '\0')
				break ;
			if (str[index] != '1' && ((x == 0 || x == width - 1) \
|| (y == 0 || y == height - 1)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	get_height(char *str)
{
	int	height;
	int	index;

	index = 0;
	height = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			height++;
		index++;
	}
	return (height + 1);
}

int	check_object_count(t_bigstruct *info, int p_check, int e_check)
{
	int	index;
	int	c_check;

	c_check = 0;
	index = 0;
	while (info->map[index] != '\0')
	{
		if (info->map[index] == 'C')
			c_check++;
		else if (info->map[index] == 'P')
			p_check++;
		else if (info->map[index] == 'E')
			e_check++;
		index++;
	}
	if (c_check < 1)
		return (exit_program(info, "too few collectibles"), 0);
	else if (p_check == 0 || p_check > 1)
		return (exit_program(info, "invalid amount of players"), 0);
	else if (e_check == 0 || e_check > 1)
		return (exit_program(info, "invalid amount of exits"), 0);
	info->updates.c_count = c_check;
	return (1);
}
