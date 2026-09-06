/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:44:33 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/28 15:19:34 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	*argv[])
{
	t_bigstruct	info;

	if (argc != 2)
		return (exit_program(&info, "invalid number of args"), 0);
	init_structs(&info);
	if (!parse_organizer(argv, &info))
		return (0);
	info.mlx = mlx_init(info.constants.width * TILE_SIZE, \
info.constants.height * TILE_SIZE, "so_long", true);
	if (!info.mlx)
		return (exit_program(&info, "MLX initialization failed"), 0);
	init_images(&info);
	visualize_map_organizer(&info);
	mlx_key_hook(info.mlx, create_keyhook, &info);
	mlx_loop(info.mlx);
	exit_program(&info, "succesfully completed");
	return (0);
}

void	init_structs(t_bigstruct *info)
{
	info->last_point_exit = false;
	info->copy = NULL;
	info->updates.check = 0;
	info->map = NULL;
	info->mlx = NULL;
	info->img_empty = NULL;
	info->img_exit = NULL;
	info->img_empty = NULL;
	info->img_star = NULL;
	info->img_wall = NULL;
	info->constants.height = 0;
	info->constants.width = 0;
	info->constants.e_x = 0;
	info->constants.e_y = 0;
	info->updates.c_count = 0;
	info->updates.exit_open = false;
	info->updates.move_counter = 0;
	info->updates.p_x = 0;
	info->updates.p_y = 0;
}
