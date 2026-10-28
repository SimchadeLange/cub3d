/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:26:39 by ede-roo           #+#    #+#             */
/*   Updated: 2026/10/25 17:53:14 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_raycast.h"

static bool	is_walkable(t_config *cfg, double x, double y)
{
	int		mx;
	int		my;
	char	*row;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= cfg->map_height || mx < 0)
		return (false);
	row = cfg->map[my];
	if (!row || mx >= (int)ft_strlen(row))
		return (false);
	return (row[mx] == '0' || ft_strchr("NSEW", row[mx]) != NULL);
}

static void	move_player(t_game *g, double dx, double dy)
{
	if (is_walkable(g->cfg, g->player.x + dx, g->player.y))
		g->player.x += dx;
	if (is_walkable(g->cfg, g->player.x, g->player.y + dy))
		g->player.y += dy;
}

static void	rotate_player(t_game *g, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = old_dir_x * cos(angle) - g->player.dir_y * sin(angle);
	g->player.dir_y = old_dir_x * sin(angle) + g->player.dir_y * cos(angle);
	g->player.plane_x = old_plane_x * cos(angle)
		- g->player.plane_y * sin(angle);
	g->player.plane_y = old_plane_x * sin(angle)
		+ g->player.plane_y * cos(angle);
}

static void	handle_keys(t_game *g)
{
	double	m;
	double	r;

	m = MOVE_SPEED * g->mlx->delta_time;
	r = ROT_SPEED * g->mlx->delta_time;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		move_player(g, g->player.dir_x * m, g->player.dir_y * m);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		move_player(g, -g->player.dir_x * m, -g->player.dir_y * m);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		move_player(g, g->player.dir_y * m, -g->player.dir_x * m);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		move_player(g, -g->player.dir_y * m, g->player.dir_x * m);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		rotate_player(g, -r);
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		rotate_player(g, r);
}

void	game_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	handle_keys(g);
	render_frame(g);
}
