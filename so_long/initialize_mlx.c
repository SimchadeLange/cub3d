/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:48:15 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/05 01:09:42 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_initialization(t_sl *sl)
{
	sl->mlx = mlx_init();
	if (!sl->mlx)
		exit((ft_printf("Error\nslw initialization failed\n"), 1));
	sl->win = mlx_new_window(sl->mlx, sl->width * TILE_SIZE, sl->height
			* TILE_SIZE, "so_long");
	if (!sl->win)
		exit((ft_printf("Error\nslw initialization failed\n"), 1));
}

void	render_map(t_sl *sl)
{
	void	*img;
	char	tile;

	sl->y = 0;
	while (sl->y < sl->height)
	{
		sl->x = 0;
		while (sl->x < sl->width)
		{
			tile = sl->map[sl->y][sl->x];
			img = sl->img_floor;
			if (tile == '1')
				img = sl->img_wall;
			else if (tile == 'C')
				img = sl->img_collectible;
			else if (tile == 'E')
				img = sl->img_exit;
			else if (tile == 'P')
				img = sl->img_player;
			mlx_put_image_to_window(sl->mlx, sl->win, img,
				sl->x * TILE_SIZE, sl->y * TILE_SIZE);
			sl->x++;
		}
		sl->y++;
	}
}

void	textures_initialisation(t_sl *sl)
{
	sl->img_player = mlx_xpm_file_to_image(sl->mlx, "./images/player.xpm",
			&sl->img_width, &sl->img_height);
	if (!sl->img_player)
		error_exit(sl, "Failed to load player.xpm");
	sl->img_wall = mlx_xpm_file_to_image(sl->mlx, "./images/wall.xpm",
			&sl->img_width, &sl->img_height);
	if (!sl->img_wall)
		error_exit(sl, "Failed to load wall.xpm");
	sl->img_floor = mlx_xpm_file_to_image(sl->mlx, "./images/floor.xpm",
			&sl->img_width, &sl->img_height);
	if (!sl->img_floor)
		error_exit(sl, "Error\nFailed to load floor.xpm");
	sl->img_collectible = mlx_xpm_file_to_image(sl->mlx,
			"./images/collectible.xpm", &sl->img_width, &sl->img_height);
	if (!sl->img_collectible)
		error_exit(sl, "Failed to load collectible.xpm");
	sl->img_exit = mlx_xpm_file_to_image(sl->mlx, "./images/exit.xpm",
			&sl->img_width, &sl->img_height);
	if (!sl->img_exit)
		error_exit(sl, "Failed to load exit.xpm");
}

void	error_exit(t_sl *sl, char *msg)
{
	ft_printf("Error\n%s\n", msg);
	cleanup(sl);
	exit(1);
}
