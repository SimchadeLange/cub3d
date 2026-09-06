/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:29:15 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/26 16:12:29 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_window(t_bigstruct *info, int new_x, int new_y)
{
	int			new_pos;
	int			old_pos;
	t_updates	*up_ptr;

	up_ptr = &info->updates;
	old_pos = up_ptr->p_x + (info->constants.width * up_ptr->p_y);
	new_pos = new_x + (info->constants.width * new_y);
	if (info->last_point_exit == true)
	{
		mlx_image_to_window(info->mlx, info->img_exit, info->updates.p_x
			* TILE_SIZE, info->updates.p_y * TILE_SIZE);
		info->map[old_pos] = 'E';
	}
	else
	{
		mlx_image_to_window(info->mlx, info->img_empty, info->updates.p_x
			* TILE_SIZE, info->updates.p_y * TILE_SIZE);
		info->map[old_pos] = '0';
	}
	mlx_image_to_window(info->mlx, info->img_player, new_x * TILE_SIZE,
		new_y * TILE_SIZE);
}

static void	update_map(t_bigstruct *info, int new_x, int new_y)
{
	int			new_pos;
	int			old_pos;
	t_updates	*up_ptr;

	up_ptr = &info->updates;
	old_pos = up_ptr->p_x + (info->constants.width * up_ptr->p_y);
	new_pos = new_x + (info->constants.width * new_y);
	if (info->map[new_pos] == 'E')
		info->last_point_exit = true;
	else
		info->last_point_exit = false;
	if (info->map[new_pos] == 'C')
		up_ptr->c_count--;
	info->map[new_pos] = 'P';
	up_ptr->p_x = new_x;
	up_ptr->p_y = new_y;
	up_ptr->move_counter++;
	ft_printf("Moves:%d,stars left%d\n", up_ptr->move_counter, up_ptr->c_count);
}

void	move_player(t_bigstruct *info, int new_x, int new_y)
{
	int	tile_pos;

	tile_pos = new_x + (info->constants.width * new_y);
	if (info->map[tile_pos] == '1')
	{
		ft_printf("thats a wall my freind\n");
		return ;
	}
	if (info->map[tile_pos] == 'E')
	{
		if (info->updates.c_count == 0)
		{
			mlx_close_window(info->mlx);
			return ;
		}
		else
		{
			ft_printf("get all the stars first impatient imp \n");
		}
	}
	update_window(info, new_x, new_y);
	update_map(info, new_x, new_y);
}

void	create_keyhook(mlx_key_data_t keydata, void *param)
{
	t_bigstruct	*info;

	info = (t_bigstruct *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	else if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_close_window(info->mlx));
	else if (keydata.key == 'W')
		move_player(info, info->updates.p_x, info->updates.p_y - 1);
	else if (keydata.key == 'A')
		move_player(info, info->updates.p_x - 1, info->updates.p_y);
	else if (keydata.key == 'S')
		move_player (info, info->updates.p_x, info->updates.p_y + 1);
	else if (keydata.key == 'D')
		move_player(info, info->updates.p_x + 1, info->updates.p_y);
	info->updates.check++;
}
