/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:43:17 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/26 16:05:40 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	visualize_map_organizer(t_bigstruct *info)
{
	t_constants	sizes;
	int			x;
	int			y;

	sizes = info->constants;
	x = 0;
	y = 0;
	while (info->map[x + (sizes.width * y)] != '\0')
	{
		if (info->map[x + (sizes.width * y)] == '\n')
		{
			y++;
			x = 0;
		}
		else
		{
			put_image(x, y, &sizes, info);
			x++;
		}
	}
	return (1);
}

void	put_image(int x, int y, t_constants *sizes, t_bigstruct *info)
{
	mlx_image_t	*texture;

	texture = NULL;
	if (info->map[x + (sizes->width * y)] == 'E')
		texture = info->img_exit;
	else if (info->map[x + (sizes->width * y)] == '0')
		texture = info->img_empty;
	else if (info->map[x + (sizes->width * y)] == 'P')
		texture = info->img_player;
	else if (info->map[x + (sizes->width * y)] == 'C')
		texture = info->img_star;
	else if (info->map[x + (sizes->width * y)] == '1')
		texture = info->img_wall;
	mlx_image_to_window(info->mlx, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	init_images(t_bigstruct *info)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("textures/empty.png");
	info->img_empty = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/exit.png");
	info->img_exit = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/player.png");
	info->img_player = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/star.png");
	info->img_star = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/wall.png");
	info->img_wall = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	if (info->img_empty == NULL || info->img_exit == NULL || \
info->img_player == NULL || info->img_star == NULL || info->img_wall == NULL)
		exit_program(info, "failed to load images");
}

char	*read_file(char *file_name, t_bigstruct *mapinfo)
{
	int		fd;
	char	buffer[1025];
	int		read_return;

	read_return = 1;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (exit_program(NULL, "fd fail"), NULL);
	mapinfo->map = ft_strdup("");
	if (!mapinfo->map)
		return (exit_program(mapinfo, "malloc fail"), NULL);
	while (read_return != 0)
	{
		read_return = read(fd, buffer, 1024);
		if (read_return == -1)
			return (exit_program(mapinfo, "readfail"), NULL);
		buffer[read_return] = '\0';
		mapinfo->copy = mapinfo->map;
		mapinfo->map = ft_strjoin(mapinfo->map, buffer);
		if (mapinfo->map == NULL)
			return (exit_program(mapinfo, "malloc failed"), NULL);
		free(mapinfo->copy);
	}
	mapinfo->copy = NULL;
	return (mapinfo->map);
}
