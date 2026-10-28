#ifndef HEADER_STRUCTS_H
# define HEADER_STRUCTS_H

# include "Resources/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1280
# define HEIGHT 720
# define MOVE_SPEED 3.0
# define ROT_SPEED 2.5

typedef enum e_returnval
{
	RETURN_SUCCES = 0,
	RETURN_FAIL,
}	t_returnval;

typedef enum  e_directions
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}	t_directions;

/*It's just "what the file said": 4 texture paths, 2 colours, the map, the start tile and letter. Parser fills it, raycaster reads it. Nothing about mlx in here.*/
typedef struct s_config
{
	char			*tex_path[4];   /* NO, SO, WE, EA */
	uint32_t		floor_rgb;      /* packed 0xRRGGBB */
	uint32_t		ceil_rgb;
	char			**map;          /* jagged, NULL-terminated */
	int				map_height;
	double			player_x;       /* center of start tile, e.g. 3.5 */
	double			player_y;
	t_directions	player_dir;
}	t_config;

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

typedef enum e_error_type
{
	SUCCESS = 0,	// No Errors.
	MLXFAIL,		// MLX42 function has failed.
	LIBFTFAIL,		// Libft function has failed.
	MEMFAIL,		// Dynamic memory allocation has failed.
	INVFILE,		// The provided file was invalid or does not exist.
	INVELEM,		// Element has invalid type identifier.
	INVELEMNUM,		// Invalid number of elements in file
	INVCLR,			// Colour is invalid.
	INVTEXPATH,		// Texture path was invalid or does not exist.
	NOTEX,			// Texture is missing.
	NOMAP,			// Map is missing.
	INVMAPCHAR,		// Map has invalid character.
	INVMAPWALL,		// Map not closed/surrounded by walls.
	NOPLAY,			// Map has no player position.
	MULTPLAY,		// Map has multiple player positions.
	READFAIL,		// Reading the file failed.
	ARGINV,			//invalid amount of args
	ERRMAX,			// Error count
}	t_error_type;

typedef struct s_rgbvalues
{
	int			index;
	int			red;
	int			green;
	int			blue;
	int			alpha;
	uint32_t	color;
}	t_rgbvalues;

typedef struct s_parser
{
	bool		map_not_empty;
	int			map_start;
	int			map_height;
	int			file_height; 	//*
	int 		fd;				//*
	int			elements;		//*
	char		**file;			//*
	char		**map_copy;
	char		**map;
	int			max_width;
	int			player_counter;
	t_config	*Data;
}				t_parser;

#endif