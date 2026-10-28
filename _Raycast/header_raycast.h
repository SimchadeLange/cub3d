#ifndef HEADER_RAYCAST_H
# define HEADER_RAYCAST_H

# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MOVE_SPEED 3.0
# define ROT_SPEED 2.5

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*screen;
	mlx_texture_t	*tex[4];
	t_config		*cfg;
	t_player		player;
}	t_game;

/*
** Per-column scratch data for the DDA.
** dir_x/dir_y   : direction of this ray
** map_x/map_y   : tile the ray is currently in (starts at the player tile)
** delta_x/_y    : distance the ray travels to cross one full tile in x / y
** side_x/_y     : distance from the player to the next x / y grid line
** step_x/_y     : -1 or +1, which way map_x / map_y moves
** side          : 0 = hit a vertical grid line (E/W wall), 1 = horizontal (N/S)
** perp_dist     : perpendicular distance camera plane -> wall (no fisheye)
** line_height   : wall slice height in pixels
** draw_start/end: first / last screen row of the wall slice
** wall_x        : where on the wall (0..1) the ray hit, for texture x
*/
typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	t_ray;

/* parser contract (real parser or stub_parser.c) */
int		parse_cub(char *path, t_config *cfg);
void	free_config(t_config *cfg);

/* raycaster */
int		run_game(t_config *cfg);
void	destroy_game(t_game *game);
void	init_player_raycast(t_game *g);
void	game_loop(void *param);
void	render_frame(t_game *g);
void	draw_column(t_game *g, t_ray *ray, int x);

/*load config*/
int	parse_cub(char *path, t_config *cfg);

#endif
