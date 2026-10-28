#include "includes/header.h"

static int	pick_texture(t_ray *ray)
{
	if (ray->side == 1 && ray->dir_y < 0)
		return (0);
	if (ray->side == 1 && ray->dir_y > 0)
		return (1);
	if (ray->side == 0 && ray->dir_x < 0)
		return (2);
	return (3);
}

static uint32_t	get_tex_color(mlx_texture_t *tex, int x, int y)
{
	uint8_t	*px;

	px = tex->pixels + ((y * tex->width + x) * 4);
	return ((px[0] << 24) | (px[1] << 16) | (px[2] << 8) | px[3]);
}

static uint32_t	wall_color(mlx_texture_t *tex, t_ray *ray, int tex_x, int y)
{
	int	tex_y;

	tex_y = (int)((y - (HEIGHT / 2 - ray->line_height / 2))
		* ((double)tex->height / ray->line_height));
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= (int)tex->height)
		tex_y = tex->height - 1;
	return (get_tex_color(tex, tex_x, tex_y));
}

void	draw_column(t_game *g, t_ray *ray, int x)
{
	mlx_texture_t	*tex;
	int				tex_x;
	int				y;

	tex = g->tex[pick_texture(ray)];
	tex_x = (int)(ray->wall_x * tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < ray->draw_start)
			mlx_put_pixel(g->screen, x, y, g->cfg->ceil_rgb);
		else if (y <= ray->draw_end)
			mlx_put_pixel(g->screen, x, y, wall_color(tex, ray, tex_x, y));
		else
			mlx_put_pixel(g->screen, x, y, g->cfg->floor_rgb);
		y++;
	}
}