#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>

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

#include "_Parser/header_parser.h"
#include "_Raycast/header_raycast.h"

#endif