/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:32:17 by ede-roo           #+#    #+#             */
/*   Updated: 2026/09/30 10:37:28 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_raycast.h"

static	void init_ray(t_game *g, t_ray *ray, int x)
{
	double_x	camera_x;

	camera_x = 2.0 * x / WIDTH - 1;//  check the bug
	ray->dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	ray->dir_y = g->player.dir_y + g->player.plane_y * camera_x;
	ray->map_x = (int)g->player.x;
	ray->map_y = (int)g->player.y;
	ray->delta_x = 1e30;
	ray->delta_y = 1e30;
	if (ray->dir_x != 0)
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y != 0)
		ray->delta_y = fabs(1 / ray->dir_y);	
}

 static	void set_step(t_game *g, t_ray *ray)
 {
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - g->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (g->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - g->player.y) * ray->delta_y;
	}
 }

static void	do_dda(t_game *g, t_ray *ray)
{
	char	*row;

	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= g->cfg->map_height
			|| ray->map_x < 0)
			return ;
		row = g->cfg->map[ray->map_y];
		if (ray->map_x >= (int)ft_strlen(row) || row[ray->map_x] == ' ')
			return ;
		if (row[ray->map_x] == '1')
			return ;
	}
}

static void	calc_wall(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_x - ray->delta_x;
	else
		ray->perp_dist = ray->side_y - ray->delta_y;
	if (ray->perp_dist < 1e-6)
		ray->perp_dist = 1e-6;
	ray->line_height = (int)(HEIGHT / ray->perp_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = g->player.y + ray->perp_dist * ray->dir_y;
	else
		ray->wall_x = g->player.x + ray->perp_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);

}

void	render_frame(t_game *g)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(g, &ray, x);
		set_step(g, &ray);
		do_dda(g, &ray);
		calc_wall(g, &ray);
		draw_column(g, &ray, x);
		x++;
	}
}
