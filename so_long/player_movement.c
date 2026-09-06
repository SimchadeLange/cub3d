/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:48:15 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/05 01:51:29 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collectibles(t_sl *sl, size_t nx, size_t ny, char next_tile)
{
	if (next_tile == 'C')
	{
		sl->collected++;
		ft_printf("You have %d diamaonds\n", sl->collected);
		sl->collectibles--;
		sl->map[ny][nx] = '0';
		if (sl->collectibles == 0 && !sl->found_all)
		{
			ft_printf("You have found all diamonds, quickly go to the exit!\n");
			sl->found_all = 1;
		}
	}
	if (next_tile == 'E')
	{
		if (sl->collectibles == 0)
		{
			ft_printf("You have won the game! Have a cookie\n");
			cleanup(sl);
		}
		else
			ft_printf("You can't exit yet! Collect all diamnonds first!\n");
		return ;
	}
}

void	move_player(t_sl *sl, size_t dx, size_t dy)
{
	size_t	nx;
	size_t	ny;
	char	next_tile;

	nx = sl->start_x + dx;
	ny = sl->start_y + dy;
	if (nx >= sl->width || ny >= sl->height)
		return ;
	next_tile = sl->map[ny][nx];
	if (next_tile == '1')
	{
		ft_printf("wall, can't go there\n");
		return ;
	}
	move_collectibles(sl, nx, ny, next_tile);
	if (next_tile != 'E' || sl->collectibles == 0)
	{
		sl->map[sl->start_y][sl->start_x] = '0';
		sl->map[ny][nx] = 'P';
		sl->start_x = nx;
		sl->start_y = ny;
		sl->moves++;
		ft_printf("Moves: %d\n", sl->moves);
	}
}

void	find_player(t_sl *sl)
{
	sl->y = 0;
	sl->x = 0;
	while (sl->y < sl->height)
	{
		sl->y++;
		while (sl->x < sl->width)
		{
			if (sl->map[sl->y][sl->x] == 'P')
			{
				sl->start_x = sl->x;
				sl->start_y = sl->y;
				return ;
			}
			sl->x++;
		}
	}
}
