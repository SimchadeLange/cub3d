#ifndef HEADER_H
# define HEADER_H

/*It's just "what the file said": 4 texture paths, 2 colours, the map, the start tile and letter. Parser fills it, raycaster reads it. Nothing about mlx in here.*/
typedef struct s_config
{
	char	*tex_path[4];   /* NO, SO, WE, EA */
	int		floor_rgb;      /* packed 0xRRGGBB */
	int		ceil_rgb;
	char	**map;          /* jagged, NULL-terminated */
	int		map_h;
	double	player_x;       /* center of start tile, e.g. 3.5 */
	double	player_y;
	char	player_dir;     /* 'N','S','E','W' */
}	t_config;

#endif