/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:03:31 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/05 02:29:31 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_sl	sl;
	char	**map;

	if (argc != 2)
		return (ft_printf("Error\ninvalid argument count\n"), 1);
	struct_initialisation(&sl);
	if (map_loading(argv, &sl) != 0)
		return (1);
	map = sl.map;
	if (map_validation(map, &sl) != 0)
		return (free_map(map), 1);
	if (route_validation(map, &sl) != 0)
		return (free_map(map), 1);
	find_player(&sl);
	mlx_initialization(&sl);
	textures_initialisation(&sl);
	render_map(&sl);
	mlx_key_hook(sl.win, key_hook, &sl);
	mlx_hook(sl.win, 17, 0L, close_window, &sl);
	mlx_loop(sl.mlx);
	cleanup(&sl);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	if (keycode == 65307)
		cleanup(sl);
	else if (keycode == 'w')
		move_player(sl, 0, -1);
	else if (keycode == 's')
		move_player(sl, 0, 1);
	else if (keycode == 'a')
		move_player(sl, -1, 0);
	else if (keycode == 'd')
		move_player(sl, 1, 0);
	mlx_clear_window(sl->mlx, sl->win);
	render_map(sl);
	return (0);
}

int	close_window(t_sl *sl)
{
	cleanup(sl);
	exit(0);
	return (0);
}

void	cleanup(t_sl *sl)
{
	if (sl->img_player)
		mlx_destroy_image(sl->mlx, sl->img_player);
	if (sl->img_wall)
		mlx_destroy_image(sl->mlx, sl->img_wall);
	if (sl->img_floor)
		mlx_destroy_image(sl->mlx, sl->img_floor);
	if (sl->img_collectible)
		mlx_destroy_image(sl->mlx, sl->img_collectible);
	if (sl->img_exit)
		mlx_destroy_image(sl->mlx, sl->img_exit);
	if (sl->map)
		free_map(sl->map);
	if (sl->win)
		mlx_destroy_window(sl->mlx, sl->win);
	if (sl->mlx)
	{
		mlx_destroy_display(sl->mlx);
		free(sl->mlx);
	}
	exit(0);
}

void	struct_initialisation(t_sl *sl)
{
	sl->map = NULL;
	sl->height = 0;
	sl->width = 0;
	sl->x = 0;
	sl->y = 0;
	sl->start_x = 0;
	sl->start_y = 0;
	sl->collectibles = 0;
	sl->collected = 0;
	sl->map_fd = 0;
	sl->player = 0;
	sl->exit = 0;
	sl->mlx = NULL;
	sl->win = NULL;
	sl->img_wall = NULL;
	sl->img_floor = NULL;
	sl->img_player = NULL;
	sl->img_collectible = NULL;
	sl->img_exit = NULL;
	sl->img_width = 0;
	sl->img_height = 0;
	sl->moves = 0;
	sl->found_all = 0;
}
