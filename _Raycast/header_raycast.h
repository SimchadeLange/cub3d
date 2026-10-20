#ifndef HEADER_RAYCAST_H
# define HEADER_RAYCAST_H

#include "../header.h"
#include "MLX42/MLX42.h"
#include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MOVE_SPEED 3.0
# define ROT_SPEED 2.5 //radians per second full turn 2.5 sec

typedef struct s_player
{
	double	x;          /* position, in tile units */
	double	y;
	double	dir_x;      /* direction vector, length 1 */
	double	dir_y;
	double	plane_x;    /* camera plane, perpendicular to dir */
	double	plane_y;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t *screen;
	mlx_texture_t *tex[4];
	t_config	*cfg;       /* map + colours live here, don't copy them */
	t_player	player;
}	t_game;

typedef struct s_ray
{
	double	dir_x;//direction of the ray
	double	dir_y;
	int		map_x;//which tile the ray is in starts at player
	int		map_y;
	double	delta_x;//how far the ray must treavel to cross one tile
	double	delta_y;
	int		side;// Which type of grid line we hit 0 = vertical  wallseast/west 1 = horizontal walls north south
	double	perp_dist;//distance from camera plan to wall
	int		line_height;// height in pixels
	int		draw_start;//first screen of wall slice above ceiling
	int		draw_end;//last screen of wall below floor
	double	wall_x;// where on wall we hit
}	t_ray;


int		parse_cub(char *path, t_config *cfg);
void	draw_column(t_game *g, t_ray *ray, int x);
void	game_loop(void *param);
void    init_player(t_game *g);
void	render_frame(t_game *g);
int		run_game(t_config *cfg);
int		init_window(t_game *game);
int		load_texture(t_game *game);
void	destroy_game(t_game *game);
void	init_player(t_game *game);
void	game_loop(void *param);
void	free_config(t_config *cfg);

#endif
